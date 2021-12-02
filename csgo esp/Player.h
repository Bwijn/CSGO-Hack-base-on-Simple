#pragma once
#include"pch.h"
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



private:

};
class LocalPlayer {
public:

	__forceinline void Reload() {
		this->entity =reinterpret_cast<Ent*>( entitylist->GetClientEntity(g_pIVEngineClient->GetLocalPlayer()));

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
	Ent* entity ;

};

extern LocalPlayer localPlayer;
extern Player enumplayer;
//Player::Player()
//{
//}
//
//Player::~Player()
//{
//}
