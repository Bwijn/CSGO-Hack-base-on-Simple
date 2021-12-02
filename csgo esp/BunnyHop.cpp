#pragma once

#include"pch.h"
//bool __fastcall hkCreateMove(void*, float frameTime, CUserCmd* cmd)
//{
//	//std::cout << "I was called" << std::endl;
//
//	if (!cmd || cmd->command_number == 0)
//	{
//		return 0;
//	}
//
//	return false;
//}
//auto static bunnyHop = false;
//void keyPress()
//{
//    if (GetAsyncKeyState(VK_SPACE))
//        bunnyHop = true;
//    else
//        bunnyHop = false;
//}
//
//
//void toggleBunny()
//{
//
//    Ent* pEntity = reinterpret_cast<Ent*>(InterFace::entitylist->GetClientEntity(1));
//
//    if (pEntity->m_fFlags& (1<<1)) // if player is in the air
//        *(int*)(dwClient + m_dwForceJump) = 4; // dont jump
//    else
//        *(int*)(dwClient + m_dwForceJump) = 5; // jump
//}
