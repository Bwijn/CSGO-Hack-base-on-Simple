#include"pch.h"
#include <stdexcept>

//InterFace Pointer -----------------------------------------------------------

IClientEntityList* entitylist;
IBaseClientDLL* g_CHLClient;
IClientMode* g_pIClientMode;
IVEngineClient* g_pIVEngineClient;
ISurface* g_VGuiSurface = nullptr;

IPanel* g_VGuiPanel = nullptr;


LPDIRECT3DDEVICE9 pD3DDevice;
std::size_t estimate_vftbl_length(std::uintptr_t** vftbl_start)
{
	MEMORY_BASIC_INFORMATION memInfo = { NULL };
	int m_nSize = 0;
	do {
		m_nSize++;
		VirtualQuery(reinterpret_cast<LPCVOID>(vftbl_start[m_nSize]), &memInfo, sizeof(memInfo));

	} while (memInfo.Protect == PAGE_EXECUTE_READ || memInfo.Protect == PAGE_EXECUTE_READWRITE);

	return m_nSize;
}
bool GetD3D9Device()
{
	//if (!pTable)
	//	return false;

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
		//pD3DDevice->Release();
		pD3D->Release();

		return true;

	}
	else
	{
		return false;
	}

	//pD3DDevice->Release();
	//
}

//void* d3d9Device[119];

namespace InterFace {

	// 控制台打印的函数指针 -----------------------------------------------------------
	//typedef void(__cdecl* MsgFn)(char const* pMsg, int va_list);

	//__int64 Msg(const char* message, int type)
	//{
	//	static auto fn = (decltype(&Msg))(GetProcAddress(GetModuleHandle(L"tier0.dll"), "Msg"));
	//	return fn(message, type);
	//}
	//------------------------------------------------------------------------------------------




	CreateInterfaceFn get_module_factory(HMODULE module)
	{
		return reinterpret_cast<CreateInterfaceFn>(GetProcAddress(module, "CreateInterface"));
	}

	void* GetInterFacePointer(LPCWSTR dllname, const char* interfacename) {
		auto createInterFace = get_module_factory(GetModuleHandle(dllname));


		int ReturnCode;
		auto InterFace = createInterFace(interfacename, &ReturnCode); // get
		if (!InterFace) {
			throw std::runtime_error(std::string("[get_interface] Failed to GetOffset interface: "));
		}

		return InterFace;
	}





	void initInterFace() {

		entitylist = reinterpret_cast<IClientEntityList*> (GetInterFacePointer(L"client.dll", "VClientEntityList003"));

		g_CHLClient = reinterpret_cast<IBaseClientDLL*> (GetInterFacePointer(L"client.dll", "VClient018"));//todo 这里为什么是018 官方Github为什么不更新

		g_pIClientMode = **reinterpret_cast<IClientMode***>((*reinterpret_cast<uintptr_t**>(g_CHLClient))[10] + 5);
		
		g_pIVEngineClient =  reinterpret_cast<IVEngineClient*> (GetInterFacePointer(L"engine.dll", VENGINE_CLIENT_INTERFACE_VERSION));
		g_VGuiSurface = reinterpret_cast<ISurface*> (GetInterFacePointer(L"vguimatsurface.dll", VGUI_SURFACE_INTERFACE_VERSION));
		
		g_VGuiPanel = reinterpret_cast<IPanel*> (GetInterFacePointer(L"vgui2.dll", VGUI_PANEL_INTERFACE_VERSION));

		//localPlayer.ent = *reinterpret_cast<Ent**>(GetModuleHandle(L"client.dll") + signatures::dwLocalPlayer);// todo 不应该在这里获取
		// get g_pClientMode 
		//g_pIClientMode = (IClientMode*) *((*(int***)g_CHLClient)[10] + 5); //mov ecx, g_pIclientmode
		//auto vTable = *(unsigned int***)g_pIClientMode;
		//auto myCreateMove_fn =(CreateMove_fn)vTable[21];// todo



		//&pD3DDevice => GetD3D9Device;
		if (!GetD3D9Device()) {
			Beep(500, 1200);
		};





	}

	//void* g_EntityList = IClientEntityList_interFace("engine.dll", "VClientEntityList003");

}