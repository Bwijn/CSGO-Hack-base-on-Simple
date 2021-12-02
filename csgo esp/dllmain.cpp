// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"

DWORD WINAPI Init(LPVOID base)

{

    while (!GetModuleHandle(L"serverbrowser.dll")) // 这里检查是否加载完毕
        Sleep(1000);

    GameScreenWindow = FindWindow(0, L"Counter-Strike: Global Offensive");


    InterFace::initInterFace();

    //HackhModule =  static_cast<HMODULE>(lpThreadParameter);
    if (Hooks::HookInit()) {//保持循环 如果退出开关打开 那就卸载hook和dll
        while (!exit_flag)
        {
            
            Sleep(1000);
        }
        //Hooks::Shutdown();

        
        FreeLibraryAndExitThread(static_cast<HMODULE>(base), 1);



        return true;
    }
    

    
    return 1;
}



BOOL WINAPI OnDllDetach()
{
//#ifdef _DEBUG
//    Utils::DetachConsole();
//#endif

    Hooks::Shutdown();

    
    delete pmenu;
    //Menu::Get().Shutdown();
    return TRUE;
}


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
    _In_opt_  LPVOID    lpvReserved

                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);



        CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)Init, hModule, 0, nullptr);
        break;
    case DLL_THREAD_ATTACH:
        break;

    case DLL_THREAD_DETACH:
        break;

    case DLL_PROCESS_DETACH:
        if (lpvReserved == nullptr)
            return OnDllDetach();
        return TRUE;

        break;


    }
    return TRUE;
}

