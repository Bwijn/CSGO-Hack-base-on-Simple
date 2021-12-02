#include"pch.h"
//#include"SDK/usercmd.h"

#pragma once
class CUserCmd;


namespace Aimbot {
	void aimTarget(CUserCmd* cmd,Ent* pLocal)
		;

	Ent* FindBestTarget();
}
