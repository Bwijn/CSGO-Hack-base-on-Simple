#include "pch.h"


HWND GameScreenWindow; // 游戏窗口句柄

//vmtf_hook hlclient_hook;
// HOOK CLASS OBJECT -----------------------
VmtHook* vmt_IClientMode;
VmtHook* vguipanel_hook;

vmtf_hook direct3d_hook;


CreateMove oCreateMove;

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
						if (options.SnapLine)
							visual.RenderSnapline();
						if (options.ESP_BOX)

							visual.RenderBox();
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
	auto	oEndScene = direct3d_hook.get_original_byDetours<EndScene>();
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
	auto pLocal = reinterpret_cast<Ent*>(entitylist->GetClientEntity(g_pIVEngineClient->GetLocalPlayer())); // TODO 替换为全局的localplayer 

	//lock view
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
			if (pLocal->m_fFlags & FL_ONGROUND)
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
	return true;
}

bool Hooks::HookInit() {

	direct3d_hook.setup(pD3DDevice);
	direct3d_hook.hookByDetours<EndScene>((char*)hkEndScene, 42, 7);

	//direct3d_hook.setup(pD3DDevice);
	//direct3d_hook.hookByIndex(42, hkEndScene);

	//hlclient_hook.setup(g_CHLClient);
	//hlclient_hook.hookByIndex(21, _CreateMove);



	vmt_IClientMode = new VmtHook(reinterpret_cast<void*>(g_pIClientMode));
	vmt_IClientMode->HookFunction(static_cast<void*>(CreateMoveFn), 24);

	vguipanel_hook = new VmtHook(reinterpret_cast<void*>(g_VGuiPanel));
	vguipanel_hook->HookFunction(hkPaintTraverse, 41);



	return true;


}

void Hooks::unloadhook() {


	//pmenu->Shutdown();

	//pD3DDevice->Release();
}

