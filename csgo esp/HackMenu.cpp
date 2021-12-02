//#pragma once
#pragma once
#include"pch.h"
//static bool demo_checkboxflag;
//#include"pch.h"

bool exit_flag = false;
bool MenuInitFlag = false;

Menu* pmenu = new Menu;

Options options;

WNDPROC oWndProc;
extern LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void Menu::showPlayerList()
{

}

void Menu::Shutdown()
{
	SetWindowLongPtr(GameScreenWindow, GWL_WNDPROC, (LONG_PTR)oWndProc);

	ImGui_ImplDX9_Shutdown();
	//cl_mouseenable->SetValue(true);
}

void Menu::Show() {
	_show = !_show;
};
void Menu::InitImGui(LPDIRECT3DDEVICE9 pDevice)
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\msyh.ttc", 18.0f, NULL, io.Fonts->GetGlyphRangesChineseFull());

	IM_ASSERT(font != NULL);


	ImGui_ImplWin32_Init(GameScreenWindow);
	ImGui_ImplDX9_Init(pDevice);
}

bool Menu::init() {

	if (GameScreenWindow)
	{
		oWndProc = (WNDPROC)SetWindowLongPtr(GameScreenWindow, GWL_WNDPROC, (LONG_PTR)WndProc);
		return true;

	}
	return false;

}
void Menu::Render() {

	if (!this->_show)
	{
		return;
	}

	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();


	ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_MenuBar;

	ImGui::Begin("ImGui Window", 0, window_flags);
	if (ImGui::Button(u8"退出-关闭辅助", ImVec2{ 150, 25 }))
	{

		exit_flag = true;
	}


	/// <summary>
	/// Tabs
	/// </summary>
	ImGuiTabBarFlags tab_bar_flags = ImGuiTabBarFlags_None;
	if (ImGui::BeginTabBar("MyTabBar", tab_bar_flags))
	{
		if (ImGui::BeginTabItem(u8"透视"))
		{
			ImGui::Checkbox(u8"透视功能", &options.ESP_Draw); // todo 
			//ImGui::RadioButton("radio a", &e, 0); ImGui::SameLine();
			//ImGui::RadioButton("radio b", &e, 1); ImGui::SameLine();


			ImGui::Checkbox(u8"透视线", &options.SnapLine); ImGui::SameLine();
			ImGui::Checkbox(u8"透视框", &options.ESP_BOX);
			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem(u8"伞兵功能 (待开发)"))
		{
			ImGui::Checkbox(u8"英雄联盟锁镜头（FPS游戏中的伞兵功能）", &options.LockViewAngle);
			ImGui::Checkbox(u8"连跳", &options.BunnyHop);
			ImGui::Checkbox(u8"十字准星", &options.crosshair);
			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem(u8"调试"))
		{
			ImGui::Text(u8"当前ID (clientId): %d", &localPlayer->clientId);

			ImGui::SliderInt("slider int", &options.PlayerIndex, 0, 10);

			auto ent = reinterpret_cast<Ent*>(entitylist->GetClientEntity(options.PlayerIndex));
			ImGui::TextColored(ImVec4(0.5f, 0.0f, 0.0f, 1.0f),u8"游戏中最大Entity数值 %d", entitylist->GetMaxEntities());
			ImGui::Text(u8"当前CBasePlayer的指针: %p", ent);

			if (ent && ent->IsPlayer()) {

				ImGui::TextColored(ImVec4(1.0f, 0.0f, 1.0f, 1.0f), "Index: %d", ent->clientId); /*ImGui::SameLine();*/
				ImGui::TextColored(ImVec4(1.0f, 0.0f, 1.0f, 1.0f), "lifeState: %d", ent->lifeState);
				ImGui::TextColored(ImVec4(1.0f, 0.0f, 1.0f, 1.0f), "isDormant %d", ent->isDormant);
				ImGui::TextColored(ImVec4(1.0f, 0.0f, 1.0f, 1.0f), "m_iHealth: %d", ent->m_iHealth);
				ImGui::TextColored(ImVec4(1.0f, 0.0f, 1.0f, 1.0f), "TeamNum %d", ent->TeamNum);
				ImGui::TextColored(ImVec4(1.0f, 1.0f, 0.0f, 1.0f), "origin X:%f    Y:%f    Z:%f", ent->origin.x, ent->origin.y, ent->origin.z);
			}
			ImGui::EndTabItem();
		}
		ImGui::EndTabBar();
	}






	//if (ImGui::Button("pEntity health")) {

	try {
		//Ent* pEntity = reinterpret_cast<Ent*>(entitylist->GetClientEntity(1));

		//if (pEntity)
		//{
		//	ImGui::Text("pEntity->m_iHealth: %d", pEntity->m_iHealth);
		//}
		////g_CHLClient
		//ImGui::Text("g_CHLClient->%p", g_CHLClient);
		////ImGui::Text("g_CHLClient->Connect()->%p", &(g_CHLClient->Connect));

	}
	catch (...) {
		//std::runtime_error(std::string("Ent* pEntity ERROR!!!"));

	}





	//ImGui::Checkbox(u8"方框透视", &demo_checkboxflag);
	//ImGui::Text("%p\n", d3d9Device[42]);
	ImGui::End();

	ImGui::EndFrame();
	ImGui::Render();
	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());

}

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {


	switch (uMsg)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_INSERT:
			pmenu->Show();
			break;
		case VK_F1:
			//g_Engine.Con_Printf("KEY - - - F1\n");
			break;
		case VK_NUMPAD1:
			//g_Engine.Con_Printf("KEY - - - PAD1\n");
			break;
		case VK_ESCAPE:

			//g_Engine.Con_Printf("KEY - - - ESC\n");
			break;
		}



	}
	if (pmenu->_show && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}