#include"pch.h"
#include <stdexcept>

//InterFace Pointer -----------------------------------------------------------

IClientEntityList* entitylist;
IBaseClientDLL* g_CHLClient;
IClientMode* g_pIClientMode;
IVEngineClient* g_pIVEngineClient;
ISurface* g_VGuiSurface = nullptr;
IVModelInfoClient* g_MdlInfo = nullptr;

IPanel* g_VGuiPanel = nullptr;


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
		g_MdlInfo = reinterpret_cast<IVModelInfoClient*> (GetInterFacePointer(L"engine.dll", "VModelInfoClient004"));


		//localPlayer.ent = *reinterpret_cast<Ent**>(GetModuleHandle(L"client.dll") + signatures::dwLocalPlayer);// todo 不应该在这里获取
		// get g_pClientMode 
		//g_pIClientMode = (IClientMode*) *((*(int***)g_CHLClient)[10] + 5); //mov ecx, g_pIclientmode
		//auto vTable = *(unsigned int***)g_pIClientMode;
		//auto myCreateMove_fn =(CreateMove_fn)vTable[21];// todo









	}

	//void* g_EntityList = IClientEntityList_interFace("engine.dll", "VClientEntityList003");

}