#pragma once
#include"csgoSDK.h"
//#include"../Player.h"
#define STR_MERGE_IMPL(a, b) a##b
#define STR_MERGE(a, b) STR_MERGE_IMPL(a, b)
#define MAKE_PAD(size) STR_MERGE(_pad, __COUNTER__)[size]
#define DEFINE_MEMBER_N(type, name, offset) struct {unsigned char MAKE_PAD(offset); type name;}



extern IVEngineClient* g_pIVEngineClient;
extern IVModelInfoClient* g_MdlInfo;
//extern LocalPlayer localPlayer;
//extern Player enumplayer;

//struct vec3 { float x, y, z; };
template<typename FuncType>
__forceinline static FuncType CallVFunction(void* ppClass, int index)
{
	int* pVTable = *(int**)ppClass;
	int dwAddress = pVTable[index];
	return (FuncType)(dwAddress);
}


class Ent //:public IClientEntity
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
		DEFINE_MEMBER_N(Vector, eye_pos,offsets::m_vecViewOffset);
		DEFINE_MEMBER_N(bool, isDormant, signatures::m_bDormant);
		DEFINE_MEMBER_N(unsigned char, lifeState, offsets::m_lifeState);
		DEFINE_MEMBER_N(int, TeamNum, offsets::m_iTeamNum);
		DEFINE_MEMBER_N(studiohdr_t*, m_pStudioHdr, signatures::m_pStudioHdr);
		//DEFINE_MEMBER_N(Vector, eye_pos, offsets::m_vecViewOffset);
	};

	//inline bool isdormant()
	//{
	//	return getvfunc<bool(__thiscall*)(void)>((this + 0x8), 9)();
	//}
	inline bool          IsAlive() {
		return lifeState == LIFE_ALIVE;


	};
	//inline bool isEnemy() {
	//return localPlayer->TeamNum != this->TeamNum;

	//}
	inline bool IsPlayer() {
		return CallVFunction<bool(__thiscall*)(Ent*)>(this, 152)(this);
	}
	//Vector GetHeadPos() {
	//	auto v = Vector{};

	//	//DWORD dwEntity = *(DWORD*)((m_dwEntityList + (i * 0x10)));
	//	DWORD dwBoneMatrix = *(DWORD*)((DWORD)this + offsets::m_dwBoneMatrix);
	//	v.x = *(float*)(dwBoneMatrix + 0x30 * 8 + 0x0C);
	//	v.y = *(float*)(dwBoneMatrix + 0x30 * 8 + 0x1C);
	//	v.z = *(float*)(dwBoneMatrix + 0x30 * 8 + 0x2C);
	//	return v;
	//}
	Vector GetBones(int Boneindex) {
		auto v = Vector{};

		//DWORD dwEntity = *(DWORD*)((m_dwEntityList + (i * 0x10)));
		DWORD dwBoneMatrix = *(DWORD*)((DWORD)this + offsets::m_dwBoneMatrix);
		v.x = *(float*)(dwBoneMatrix + 0x30 * Boneindex + 0x0C);
		v.y = *(float*)(dwBoneMatrix + 0x30 * Boneindex + 0x1C);
		v.z = *(float*)(dwBoneMatrix + 0x30 * Boneindex + 0x2C);
		return v;
	}


	//通过就虚函数索引获取的函数 
	bool SetupBones(matrix3x4_t* out, int max_bones, int mask, float time) {
		if (!this) return false;
		using original_fn = bool(__thiscall*)(void*, matrix3x4_t*, int, int, float);
		IClientRenderable* IClientRenderableVtable = (IClientRenderable*)((DWORD)this + 0x4);
		return (*(original_fn**)IClientRenderableVtable)[13](IClientRenderableVtable, out, max_bones, mask, time);
	}
	auto	GetModel() {
		//if (!this) return ;
		using original_fn = const model_t* (__thiscall*)(void*);
		IClientRenderable* IClientRenderableVtable = (IClientRenderable*)((DWORD)this + 0x4);
		return (*(original_fn**)IClientRenderableVtable)[8](IClientRenderableVtable);
	}
	Vector GetHitboxPos(int hitbox_id)
	{
		matrix3x4_t boneMatrix[MAXSTUDIOBONES];

		if (SetupBones(boneMatrix, MAXSTUDIOBONES, BONE_USED_BY_HITBOX, 0.0f)) {
			auto studio_model = g_MdlInfo->GetStudiomodel(GetModel());
			if (studio_model) {
				auto hitbox = studio_model->GetHitboxSet(0)->GetHitbox(hitbox_id);

				if (hitbox) {
					auto
						min = Vector{},
						max = Vector{};

					Math::VectorTransform(hitbox->bbmin, boneMatrix[hitbox->bone], min);
					Math::VectorTransform(hitbox->bbmax, boneMatrix[hitbox->bone], max);

					return (min + max) / 2.0f;
				}
			}
		}
		return Vector{};
	}


	player_info_t GetPlayerInfo() {

		player_info_t info;
		g_pIVEngineClient->GetPlayerInfo(clientId, &info);
		return info;

	};


//bool isEnemy

}; //Size: 0x0284


