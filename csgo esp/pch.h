// pch.h: 这是预编译标头文件。
// 下方列出的文件仅编译一次，提高了将来生成的生成性能。
// 这还将影响 IntelliSense 性能，包括代码完成和许多代码浏览功能。
// 但是，如果此处列出的文件中的任何一个在生成之间有更新，它们全部都将被重新编译。
// 请勿在此处添加要频繁更新的文件，这将使得性能优势无效。
#pragma once

#ifndef PCH_H
#define PCH_H
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

// 添加要在此处预编译的标头
#include <d3d9.h>
#include <d3dx9.h>

#include <Windows.h>
#include<stdexcept>
#include<iostream>


#include"imgui/imgui.h"
#include"imgui/imgui_impl_dx9.h"
#include"imgui/imgui_impl_win32.h"

//#include"valve_sdk/interfaces/IClientEntity.hpp"  // sdk.hpp inline 关键字错误 为什么在函数外面定义变量
//#include"valve_sdk/interfaces/IClientEntity.hpp"
//#include"valve_sdk/sdk.hpp"
//#include"valve_sdk/csgostructs.hpp"

#include"SDK/csgoSDK.h" // valve_sdk是没整理的SDK  SDK文件夹是自己的边写边整理的可用文件夹
//#include"SDK/IClientInterface.h" // valve_sdk是没整理的SDK  SDK文件夹是自己的边写边整理的可用文件夹

#include"CSGO_offsets.h"

//#include"cvh.hpp" // 测试用 Cheat项目中的源码虚函数hook类
#include"tools/math.hpp"
#include"guidedhacking_cvmt.hpp"
#include"Cvmtf_hook.h"
#include"mem.h"
#include"hook.h"
#include"InterfaceManager.h"
#include"HackMenu.h"
#include"BunnyHop.h"
#include"Visual.h"
#include"Player.h"



#endif
