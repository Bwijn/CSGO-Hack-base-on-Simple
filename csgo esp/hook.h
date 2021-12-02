#pragma once
#include"pch.h"


//extern HMODULE HackhModule; // µ±Ç°hackdll µÄmodule 
//void InitImGui(LPDIRECT3DDEVICE9 pDevice);
//extern void* d3d9Device[119];


extern HWND GameScreenWindow;


using EndScene = long(__stdcall*)(IDirect3DDevice9*);
using Reset = long(__stdcall*)(IDirect3DDevice9*, D3DPRESENT_PARAMETERS*);
//using CreateMove = void(__thiscall*)(IBaseClientDLL*, int, float, bool);
using CreateMove = void(__fastcall*)(void* thisptr, void* not_edx,float flInputSampleTime, CUserCmd* cmd);
using PaintTraverse = void(__thiscall*)(IPanel*, vgui::VPANEL, bool, bool);


//HRESULT APIENTRY hkEndScene(LPDIRECT3DDEVICE9 pDevice);
//extern EndScene oEndScene;

namespace Hooks
{


    //using PaintTraverse = void(__thiscall*)(IPanel*, vgui::VPANEL, bool, bool);
    //using FrameStageNotify = void(__thiscall*)(IBaseClientDLL*, ClientFrameStage_t);
    //using PlaySound = void(__thiscall*)(ISurface*, const char* name);
    //using DrawModelExecute = void(__thiscall*)(IVModelRender*, IMatRenderContext*, const DrawModelState_t&, const ModelRenderInfo_t&, matrix3x4_t*);
    //using FireEvent = bool(__thiscall*)(IGameEventManager2*, IGameEvent* pEvent);
    //using DoPostScreenEffects = int(__thiscall*)(IClientMode*, int);
    //using OverrideView = void(__thiscall*)(IClientMode*, CViewSetup*);


	bool HookInit();

	void Shutdown();

	

	
}

namespace index
{
    constexpr auto EndScene = 42;
    constexpr auto Reset = 16;
    constexpr auto PaintTraverse = 41;
    constexpr auto CreateMove = 24;
    constexpr auto PlaySound = 82;
    constexpr auto FrameStageNotify = 36;
    constexpr auto DrawModelExecute = 21;
    constexpr auto DoPostScreenSpaceEffects = 44;
    constexpr auto SvCheatsGetBool = 13;
    constexpr auto OverrideView = 18;
}

