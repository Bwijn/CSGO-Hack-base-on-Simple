#include"../CSGO_offsets.h"
#include"IClientInterface.h"
#include"IVEngineClient.hpp"
#include"Color.hpp"
#include"IPanel.hpp"
#include"ISurface.hpp"
#include"usercmd.h"
#include"QAngle.hpp"
#include"Enums.hpp"
#include"IAppSystem.hpp"
#pragma once
#define STR_MERGE_IMPL(a, b) a##b
#define STR_MERGE(a, b) STR_MERGE_IMPL(a, b)
#define MAKE_PAD(size) STR_MERGE(_pad, __COUNTER__)[size]
#define DEFINE_MEMBER_N(type, name, offset) struct {unsigned char MAKE_PAD(offset); type name;}
//struct vec3 { float x, y, z; };
template<typename FuncType>
__forceinline static FuncType CallVFunction(void* ppClass, int index)
{
	int* pVTable = *(int**)ppClass;
	int dwAddress = pVTable[index];
	return (FuncType)(dwAddress);
}


class Ent
{

	//Ent& operator=(const Ent& ent) { return *this; };
	//
	//bool operator==(const Ent& ent) { return true ? 1 : 0; };
public:
	//struct { char _pad26[offsets::m_iHealth]};
	union
	{
		DEFINE_MEMBER_N(int, m_fFlags, offsets::m_fFlags);
		DEFINE_MEMBER_N(Vector, origin, offsets::m_vecOrigin);
		DEFINE_MEMBER_N(int, clientId, 0x64);
		DEFINE_MEMBER_N(int, m_iHealth, offsets::m_iHealth);
		DEFINE_MEMBER_N(Vector, m_vecViewOffset, offsets::m_vecViewOffset);
		DEFINE_MEMBER_N(bool, isDormant, signatures::m_bDormant);
		DEFINE_MEMBER_N(unsigned char, lifeState, offsets::m_lifeState);
		DEFINE_MEMBER_N(int, TeamNum, offsets::m_iTeamNum);
	};

	//inline bool isdormant()
	//{
	//	return getvfunc<bool(__thiscall*)(void)>((this + 0x8), 9)();
	//}
	inline bool          IsAlive() {
		return lifeState == LIFE_ALIVE;


	};
	inline bool IsPlayer() {
		return CallVFunction<bool(__thiscall*)(Ent*)>(this, 152)(this);
	}
	Vector GetHeadPos() {
		auto v = Vector{};
		
		//DWORD dwEntity = *(DWORD*)((m_dwEntityList + (i * 0x10)));
		DWORD dwBoneMatrix = *(DWORD*)((DWORD)this + offsets::m_dwBoneMatrix);
		v.x = *(float*)(dwBoneMatrix + 0x30 * 8 + 0x0C);
		v.y = *(float*)(dwBoneMatrix + 0x30 * 8 + 0x1C);
		v.z = *(float*)(dwBoneMatrix + 0x30 * 8 + 0x2C);
		return v;
	}

}; //Size: 0x0284


