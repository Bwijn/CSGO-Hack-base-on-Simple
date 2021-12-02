#include "pch.h"

#include<math.h>
HWND GameScreenWindow; // 游戏窗口句柄
LPDIRECT3DDEVICE9 pD3DDevice;//全局的d3d9设备指针

//vmtf_hook hlclient_hook;
// HOOK CLASS OBJECT -----------------------
VmtHook* vmt_IClientMode;
VmtHook* vguipanel_hook;

vmtf_hook* direct3d_hook;




//--------------------------------------------------------------------------------
void __stdcall hkPaintTraverse(vgui::VPANEL panel, bool forceRepaint, bool allowForce)
{
	//static auto oPaintTraverse = reinterpret_cast<PaintTraverse>(vguipanel_hook->GetOriginalFunction(index::PaintTraverse));

	//oPaintTraverse(g_VGuiPanel, panel, forceRepaint, allowForce);



	static auto panelId = vgui::VPANEL{ 0 };
	static auto oPaintTraverse = vguipanel_hook->GetOriginalFunction<PaintTraverse>(index::PaintTraverse);

	oPaintTraverse(g_VGuiPanel, panel, forceRepaint, allowForce);

	if (!panelId) {
		const auto panelName = g_VGuiPanel->GetName(panel);
		if (!strcmp(panelName, "FocusOverlayPanel")) {
			panelId = panel;
		}
	}
	else if (panelId == panel) {


		if (options.ESP_Draw && g_pIVEngineClient->IsInGame())
		{

			for (auto i = 1; i <= entitylist->GetHighestEntityIndex(); ++i) {

				auto entity = reinterpret_cast<Ent*>(entitylist->GetClientEntity(i));

				if (!entity)
					continue;
				if (!entity->IsPlayer())
					continue;
				if (localPlayer.operator==(entity) ||
					(entity->clientId == localPlayer->clientId))
					continue;
				if (i < 65 && !entity->isDormant && entity->IsAlive()) {

					if (visual.Begin(entity)) {
						if (options.SnapLine)	visual.RenderSnapline();
						if (options.ESP_BOX)	visual.RenderBox();
						if (options.esp_player_names)     visual.RenderName();
						if (options.ESP_Bones)     visual.RenderBones();


					}
				}
			}
		}




		if (options.crosshair)
			visual.RenderCrosshair();
	}
}

//--------------------------------------------------------------------------------

HRESULT APIENTRY hkEndScene(LPDIRECT3DDEVICE9 pDevice)
{

	if (!MenuInitFlag)
	{

		pmenu->init();
		pmenu->InitImGui(pDevice);
		MenuInitFlag = true;
	}
	auto	oEndScene = direct3d_hook->get_original_byDetours<EndScene>();
	//auto	oEndScene = v_hook->GetOriginalFunction<EndScene>(42);

	//if (bInit == false)
	//{
	//	//pD3DDevice = pDevice;
	//	InitImGui(pDevice);
	//	bInit = true;
	//}



	pmenu->Render();
	//ShowImguiMenu();

	return oEndScene(pDevice);
}

bool __fastcall CreateMoveFn(void* thisptr, void* not_edx, float SampleTime, CUserCmd* cmd)
{
auto pLocal=	reinterpret_cast<Ent*>(entitylist->GetClientEntity(g_pIVEngineClient->GetLocalPlayer()));



	//伞兵功能 锁视角
	if (options.LockViewAngle)
	{
		cmd->viewangles.y = 90;
		cmd->viewangles.x = 0;
	}

	//if (!cmd->command_number)
	//	return true; // Check digit
	if (options.BunnyHop) {
		static bool bLastJumped = false;
		static bool bShouldFake = false;

		if (!bLastJumped && bShouldFake)
		{
			bShouldFake = false;
			cmd->buttons |= IN_JUMP;
		}
		else if (cmd->buttons & IN_JUMP)
		{
			if (localPlayer->m_fFlags & FL_ONGROUND)
			{
				bLastJumped = true;
				bShouldFake = true;
			}
			else
			{
				cmd->buttons &= ~IN_JUMP;
				bLastJumped = false;
			}
		}
		else
		{
			bLastJumped = false;
			bShouldFake = false;
		}
	}
	//auto oCM = vmt_IClientMode->GetOriginalFunction<CreateMove>(24);
	//oCM(SampleTime, cmd);
	if (options.aimbot&&(cmd->buttons&IN_ATTACK))
	{
		// todo 选头 选身子
		Aimbot::aimTarget(cmd, pLocal);
	

	}
	return true;
}




bool GetD3D9Device()
{

	IDirect3D9* pD3D = Direct3DCreate9(D3D_SDK_VERSION);

	if (!pD3D)
		return false;

	//IDirect3DDevice9* pDummyDevice = NULL;

	// options to create dummy device
	D3DPRESENT_PARAMETERS d3dpp = {};
	d3dpp.Windowed = false;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = GameScreenWindow;//  hwnd gamewindow

	HRESULT dummyDeviceCreated = pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, d3dpp.hDeviceWindow, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &pD3DDevice);

	if (dummyDeviceCreated != S_OK)
	{
		// may fail in windowed fullscreen mode, trying again with windowed mode
		d3dpp.Windowed = !d3dpp.Windowed;

		dummyDeviceCreated = pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, d3dpp.hDeviceWindow, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &pD3DDevice);

		if (dummyDeviceCreated != S_OK)
		{

			pD3D->Release();
			return false;
		}
	}

	//auto vptr = *(void***)pD3DDevice;
	//SIZE_T ulOldProtect = 0;
	//VirtualProtect(&vptr[42], sizeof(void*), PAGE_EXECUTE_READWRITE, &ulOldProtect);
	//oEndScene = (EndScene)vptr[42];
	//auto aa = (uintptr_t)hkEndScene;
	//vptr[42] = hkEndScene;
	//赋给全局的 pD3DDevice 指针
   //pD3DDevice = pDummyDevice;
	if (pD3DDevice)
	{
		pD3D->Release();
		//pD3DDevice->Release(); 


		return true;

	}
	else
	{
		return false;
	}

	//pD3DDevice->Release();
	//
}

bool Hooks::HookInit() {

	//&pD3DDevice => GetD3D9Device;
	if (!GetD3D9Device()) {
		Beep(500, 1200);
	};

	direct3d_hook = new vmtf_hook(pD3DDevice);//

	direct3d_hook->hookByDetours((char*)hkEndScene, index::EndScene, 7);

	//direct3d_hook.setup(pD3DDevice);
	//direct3d_hook.hookByIndex(42, hkEndScene);

	//hlclient_hook.setup(g_CHLClient);
	//hlclient_hook.hookByIndex(21, _CreateMove);



	vmt_IClientMode = new VmtHook(reinterpret_cast<void*>(g_pIClientMode));
	vmt_IClientMode->HookFunction(static_cast<void*>(CreateMoveFn), 24);

	vguipanel_hook = new VmtHook(reinterpret_cast<void*>(g_VGuiPanel));
	vguipanel_hook->HookFunction(hkPaintTraverse, 41);

	visual.CreateFonts();



	return true;


}

void Hooks::Shutdown()
{

	vmt_IClientMode->UnhookFunction(index::CreateMove);
	vguipanel_hook->UnhookFunction(index::PaintTraverse);
	direct3d_hook->unhook(index::EndScene);

	delete direct3d_hook;
	delete vmt_IClientMode;
	delete vguipanel_hook;
	pD3DDevice->Release();

	//auto r=	direct3d_hook.

}

//void Hooks::unloadhook() {
//
//
//	//pmenu->Shutdown();
//
//	//pD3DDevice->Release();
//}

