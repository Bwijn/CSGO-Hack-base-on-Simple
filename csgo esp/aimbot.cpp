//#include "aimbot.h"
#include"pch.h"
#pragma once
const float  PI = 3.1415926;
const float radian = 57.29578;

//extern LocalPlayer localPlayer;

void Aimbot:: aimTarget(CUserCmd* cmd, Ent* pLocal)

{


	// Search the best enemy
	float lowestDistance = -1;
	Ent* bestEnemy = nullptr;

	for (int i = 0; i < entitylist->GetHighestEntityIndex(); i++) {
		auto entity = reinterpret_cast<Ent*>(entitylist->GetClientEntity(i));
		//auto isEnemy =
		if (!entity) {
			continue;
		}
		if (!entity->IsPlayer())
			continue;
		if (!entity->IsAlive())
		{
			continue;
		}
	
		if (i > 64 || entity->isDormant || !(pLocal->TeamNum != entity->TeamNum)) {
			continue;
		}

		auto target_head_pos = entity->GetHitboxPos(HITBOX_HEAD);
		auto my_eye_pos = pLocal->eye_pos;
		auto distance = Math::VectorDistance(target_head_pos, my_eye_pos);

		//auto distance  = 
		if (lowestDistance == -1 || distance < lowestDistance) {
			lowestDistance = distance;
			bestEnemy = entity;
		}
	}
	if (!bestEnemy)
	{
		return;
	}



	////auto target = Aimbot::FindBestTarget();
	//if (!target)
	//{
	//	return;
	//}
	
	//¶Ô±ß³ýÒÔÐ±±ß * »¡¶È
	auto target_head_pos =bestEnemy->GetHitboxPos(HITBOX_HEAD);
	auto my_eye_pos =pLocal->GetHitboxPos(HITBOX_HEAD);
	auto distance = Math::VectorDistance(target_head_pos, my_eye_pos);
	Vector deltaDistance = target_head_pos - my_eye_pos;

	
	auto pitch = -asin(deltaDistance.z / distance) * (180 / PI);
	auto yaw = atan2(deltaDistance.y, deltaDistance.x) * (180 / PI);
	
	if (pitch >= -89 && pitch <= 89 && yaw >= -180 && yaw <= 180)
	{
		cmd->viewangles.x = pitch;
		cmd->viewangles.y = yaw;

	}

};

Ent* Aimbot::FindBestTarget()
{
	// Search the best enemy
	auto me= reinterpret_cast<Ent*>(entitylist->GetClientEntity(g_pIVEngineClient->GetLocalPlayer()));
	float lowestDistance = -1;
	Ent* bestEnemy=nullptr;

	for (int i = 0; i < entitylist->GetHighestEntityIndex(); i++) {
		auto entity = reinterpret_cast<Ent*>(entitylist->GetClientEntity(i));
		//auto isEnemy =
		if (!entity) {
			continue;
		}
		if (!entity->IsPlayer())
			continue;
		if (i<65&&entity->isDormant&& !(me->TeamNum != entity->TeamNum) &&!entity->IsAlive()) {
			continue;
		}
		
		auto target_head_pos = entity->GetHitboxPos(HITBOX_HEAD);
		auto my_eye_pos = me->GetHitboxPos(HITBOX_HEAD);
		auto distance = Math::VectorDistance(target_head_pos, my_eye_pos);

		//auto distance  = 
		if (lowestDistance == -1 || distance < lowestDistance) {
			lowestDistance = distance;
			bestEnemy = entity;
		}
	}
	if (bestEnemy)
	{
		return bestEnemy;
	}

	return nullptr;
}
