#pragma once
#include"pch.h"
//void ShowImguiMenu();
//void show_hookBytes_State();
class Menu;
class Options;
extern Menu* pmenu;
extern bool MenuInitFlag;

extern bool exit_flag;
extern Options options;

class Menu {

public:
	//Menu()=delete;
	void Render();
	bool init();
	void InitImGui(LPDIRECT3DDEVICE9 pDevice);
	void Show();
	void Shutdown();


	void showPlayerList();
public:
	bool _show = false;

	//static	LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);



};

class Options {
public:
	Options() {
		crosshair_color.SetColor(255, 0, 0);// initial the Color value
	};
public:
	//struct
	//{
	bool BunnyHop = false;
	bool		LockViewAngle = false;
	bool crosshair=false;

	Color crosshair_color ;
	 
//-----------------ESP----------------------------
	bool ESP_Draw=true;
	//int ESP_Draw=0;

	bool SnapLine=false;
	bool ESP_BOX=false;
// debug
	int PlayerIndex = 0;
	
	//};

};
