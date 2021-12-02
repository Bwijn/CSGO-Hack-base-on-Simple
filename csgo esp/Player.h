#pragma once
#include"pch.h"
class Bone {

	//Bone(Ent*ent,unsigned int index);
//	Bone() = delete;
//
//
//public:
//	 unsigned int BoneIndex;
//
//	matrix3x4_t boneMatrix;
//	Vector bonePos;
//
//	Vector GetPos();
public:
	Vector Pos;
	Vector ScreenPos;
};
class Player
{
public:
	//Player();
	//~Player();
	Ent* ent;
	bool isEnemy;
	Color clr;
	RECT          bbox; // box¶ÔÏó



	Vector        head_pos;
	Vector        feet_pos;

	//If you want to just scan important bonesand skip the hitbox part, scan the bone indexes : { 8, 4, 3, 7, 6, 5 }
	Bone HEAD;//8
	Bone NECK;//7

	Bone BODY6;//6
	Bone BODY5;//5
	Bone BODY4;//4
	Bone BODY3;//3 //STOMACH

	Bone PELVIS;//Åè¹Ç

	Bone LShoulder;//11
	Bone LArm1;//12
	Bone LArm2;//13

	Bone RShoulder;//41
	Bone RArm1;//42
	Bone RArm2;//43


	Bone LLag1;
	Bone LLag2;
	Bone LLag3;
	
	Bone RLag1;
	Bone RLag2;
	Bone RLag3;
	

	//bool UpdateAllBones();


};
class LocalPlayer {
public:

	__forceinline void Reload() {
		this->entity = reinterpret_cast<Ent*>(entitylist->GetClientEntity(g_pIVEngineClient->GetLocalPlayer()));

	}
	bool operator==(Ent* ent) {
		if (this->entity == nullptr) {
			Reload();
		}
		if (ent == this->entity)
		{
			return true;
		}
		else
		{
			return false;
		}


	};

	__forceinline Ent* operator->() {

		if (this->entity == nullptr)
		{
			Reload();
		}
		return	 this->entity;
	};
	//private:
	Ent* entity;

};





extern LocalPlayer localPlayer;
extern Player enumplayer;
