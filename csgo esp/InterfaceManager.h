#pragma once
#include"pch.h"

extern	IClientEntityList* entitylist;
extern 	IBaseClientDLL* g_CHLClient;
extern LPDIRECT3DDEVICE9 pD3DDevice;
extern IClientMode* g_pIClientMode;
extern IVEngineClient* g_pIVEngineClient;
extern IPanel* g_VGuiPanel ;
extern IVModelInfoClient* g_MdlInfo;

extern ISurface* g_VGuiSurface;

namespace  InterFace {

	void  initInterFace();

	
};


//typedef void* (*CreateInterfaceFn)(const char* pName, int* pReturnCode);//  ÿ��dll�ĵ����ӿ�  ���ں�clientengine ����

