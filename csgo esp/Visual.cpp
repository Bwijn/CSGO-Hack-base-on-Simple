#include "pch.h"
#include"SDK/math.hpp"
Visual visual;
vgui::HFont esp_font;

bool Visual::Begin(Ent* pl) {
	//localPlayer.ent = reinterpret_cast<Ent*>(entitylist->GetClientEntity(g_pIVEngineClient->GetLocalPlayer())); // TODO 替换为全局的localplayer 
		 //Player enumplayer 这个是临时的Player 对象 for 64 每循环一次就覆盖一次，充分利用

	enumplayer.ent = pl;
	enumplayer.isEnemy = localPlayer->TeamNum != enumplayer.ent->TeamNum;
	enumplayer.clr = enumplayer.isEnemy ? Color::Red : Color::Blue;

	auto head = pl->GetHitboxPos(HITBOX_HEAD);
	head.z += 15;

	if (!Math::WorldToScreen(pl->origin, enumplayer.feet_pos) ||
		!Math::WorldToScreen(head, enumplayer.head_pos)
		)
		return false;

	auto h = fabs(enumplayer.head_pos.y - enumplayer.feet_pos.y);
	auto w = h / 1.65f;

	enumplayer.bbox.left = static_cast<long>(enumplayer.feet_pos.x - w * 0.5f);
	enumplayer.bbox.right = static_cast<long>(enumplayer.bbox.left + w);
	enumplayer.bbox.bottom = static_cast<long>(enumplayer.feet_pos.y);
	enumplayer.bbox.top = static_cast<long>(enumplayer.head_pos.y);
	if (options.ESP_Bones)
	{
		//enumplayer.HEAD.Pos = enumplayer.ent->GetBones(8);
		//enumplayer.NECK.Pos = enumplayer.ent->GetBones(7);
		//enumplayer.BODY6.Pos = enumplayer.ent->GetBones(6);
		//enumplayer.BODY5.Pos = enumplayer.ent->GetBones(5);
		//enumplayer.BODY4.Pos = enumplayer.ent->GetBones(4);
		//enumplayer.BODY3.Pos = enumplayer.ent->GetBones(3);

		//enumplayer.LShoulder.Pos = enumplayer.ent->GetBones(11);
		//enumplayer.LArm1.Pos = enumplayer.ent->GetBones(12);
		//enumplayer.LArm2.Pos = enumplayer.ent->GetBones(13);

		//enumplayer.RShoulder.Pos = enumplayer.ent->GetBones(41);
		//enumplayer.RArm1.Pos = enumplayer.ent->GetBones(42);
		//enumplayer.RArm2.Pos = enumplayer.ent->GetBones(43);
		//
		//enumplayer.LLag1.Pos = enumplayer.ent->GetBones(70);
		//enumplayer.LLag2.Pos = enumplayer.ent->GetBones(71);
		//enumplayer.LLag3.Pos = enumplayer.ent->GetBones(72);

		//enumplayer.RLag1.Pos = enumplayer.ent->GetBones(77);
		//enumplayer.RLag2.Pos = enumplayer.ent->GetBones(78);
		//enumplayer.RLag3.Pos = enumplayer.ent->GetBones(79);



		enumplayer.HEAD.Pos = enumplayer.ent->GetHitboxPos(HITBOX_HEAD);
		enumplayer.NECK.Pos = enumplayer.ent->GetHitboxPos(HITBOX_NECK);
		enumplayer.BODY6.Pos = enumplayer.ent->GetHitboxPos(HITBOX_UPPER_CHEST);
		enumplayer.BODY5.Pos = enumplayer.ent->GetHitboxPos(HITBOX_CHEST);
		enumplayer.BODY4.Pos = enumplayer.ent->GetHitboxPos(HITBOX_LOWER_CHEST);
		enumplayer.BODY3.Pos = enumplayer.ent->GetHitboxPos(HITBOX_STOMACH);
		enumplayer.PELVIS.Pos = enumplayer.ent->GetHitboxPos(HITBOX_PELVIS);
		
		enumplayer.LShoulder.Pos = enumplayer.ent->GetHitboxPos(HITBOX_LEFT_UPPER_ARM);
		enumplayer.LArm1.Pos = enumplayer.ent->GetHitboxPos(HITBOX_LEFT_FOREARM);
		enumplayer.LArm2.Pos = enumplayer.ent->GetHitboxPos(HITBOX_LEFT_HAND);


		enumplayer.RShoulder.Pos = enumplayer.ent->GetHitboxPos(HITBOX_RIGHT_UPPER_ARM);
		enumplayer.RArm1.Pos = enumplayer.ent->GetHitboxPos(HITBOX_RIGHT_FOREARM);
		enumplayer.RArm2.Pos = enumplayer.ent->GetHitboxPos(HITBOX_RIGHT_HAND);
			
		
		enumplayer.LLag1.Pos = enumplayer.ent->GetHitboxPos(HITBOX_LEFT_THIGH);
		enumplayer.LLag2.Pos = enumplayer.ent->GetHitboxPos(HITBOX_LEFT_CALF);
		enumplayer.LLag3.Pos = enumplayer.ent->GetHitboxPos(HITBOX_LEFT_FOOT);

		enumplayer.RLag1.Pos = enumplayer.ent->GetHitboxPos(HITBOX_RIGHT_THIGH);
		enumplayer.RLag2.Pos = enumplayer.ent->GetHitboxPos(HITBOX_RIGHT_CALF);
		enumplayer.RLag3.Pos = enumplayer.ent->GetHitboxPos(HITBOX_RIGHT_FOOT);

		//enumplayer.RShoulder.Pos = enumplayer.ent->GetHitboxPos(HITBOX_RIGHT_UPPER_ARM);
		//enumplayer.RArm1.Pos = enumplayer.ent->GetHitboxPos(HITBOX_RIGHT_FOREARM);
		//enumplayer.RArm2.Pos = enumplayer.ent->GetHitboxPos(HITBOX_RIGHT_HAND);
		



		Math::WorldToScreen(enumplayer.HEAD.Pos, enumplayer.HEAD.ScreenPos);
		Math::WorldToScreen(enumplayer.NECK.Pos, enumplayer.NECK.ScreenPos);
		Math::WorldToScreen(enumplayer.BODY6.Pos, enumplayer.BODY6.ScreenPos);
		Math::WorldToScreen(enumplayer.BODY5.Pos, enumplayer.BODY5.ScreenPos);
		Math::WorldToScreen(enumplayer.BODY4.Pos, enumplayer.BODY4.ScreenPos);
		Math::WorldToScreen(enumplayer.BODY3.Pos, enumplayer.BODY3.ScreenPos);
		Math::WorldToScreen(enumplayer.PELVIS.Pos, enumplayer.PELVIS.ScreenPos);

		Math::WorldToScreen(enumplayer.LShoulder.Pos, enumplayer.LShoulder.ScreenPos);
		Math::WorldToScreen(enumplayer.LArm1.Pos, enumplayer.LArm1.ScreenPos);
		Math::WorldToScreen(enumplayer.LArm2.Pos, enumplayer.LArm2.ScreenPos);

		Math::WorldToScreen(enumplayer.RShoulder.Pos, enumplayer.RShoulder.ScreenPos);
		Math::WorldToScreen(enumplayer.RArm1.Pos, enumplayer.RArm1.ScreenPos);
		Math::WorldToScreen(enumplayer.RArm2.Pos, enumplayer.RArm2.ScreenPos);

		Math::WorldToScreen(enumplayer.LLag1.Pos, enumplayer.LLag1.ScreenPos);
		Math::WorldToScreen(enumplayer.LLag2.Pos, enumplayer.LLag2.ScreenPos);
		Math::WorldToScreen(enumplayer.LLag3.Pos, enumplayer.LLag3.ScreenPos);

		
		Math::WorldToScreen(enumplayer.RLag1.Pos, enumplayer.RLag1.ScreenPos);
		Math::WorldToScreen(enumplayer.RLag2.Pos, enumplayer.RLag2.ScreenPos);
		Math::WorldToScreen(enumplayer.RLag3.Pos, enumplayer.RLag3.ScreenPos);



	}


	return true;

	//pl->origin.
}

void Visual::RenderName()
{
	wchar_t buf[128];

	player_info_t info = enumplayer.ent->GetPlayerInfo();

	if (MultiByteToWideChar(CP_UTF8, 0, info.szName, -1, buf, 128) > 0) {
		int tw, th;
		g_VGuiSurface->GetTextSize(esp_font, buf, tw, th);

		g_VGuiSurface->DrawSetTextFont(esp_font);
		g_VGuiSurface->DrawSetTextColor(enumplayer.clr);
		g_VGuiSurface->DrawSetTextPos(enumplayer.feet_pos.x - tw / 2, enumplayer.head_pos.y - th);
		g_VGuiSurface->DrawPrintText(buf, wcslen(buf));
	}



}

bool Visual::CreateFonts()
{
	esp_font = g_VGuiSurface->CreateFont_();
	//defuse_font = g_VGuiSurface->CreateFont_();
	//dropped_weapons_font = g_VGuiSurface->CreateFont_();

	g_VGuiSurface->SetFontGlyphSet(esp_font, "Arial", 11, 700, 0, 0, FONTFLAG_DROPSHADOW);
	//g_VGuiSurface->SetFontGlyphSet(defuse_font, "Arial", 15, 700, 0, 0, FONTFLAG_DROPSHADOW);
	//g_VGuiSurface->SetFontGlyphSet(dropped_weapons_font, "Arial", 10, 700, 0, 0, FONTFLAG_DROPSHADOW);

	return true;

	return false;
}

void Visual::RenderCrosshair() {
	//auto clr = enumplayer.ent
	int w, h;

	g_pIVEngineClient->GetScreenSize(w, h);


	//g_VGuiSurface->DrawSetColor(options.crosshair_color);
	g_VGuiSurface->DrawSetColor(Color::Red);

	int cx = w / 2;
	int cy = h / 2;

	g_VGuiSurface->DrawLine(cx - 25, cy, cx + 25, cy);
	g_VGuiSurface->DrawLine(cx, cy - 25, cx, cy + 25);

}
void Visual::RenderSnapline()
{
	int screen_w, screen_h;
	g_pIVEngineClient->GetScreenSize(screen_w, screen_h);

	g_VGuiSurface->DrawSetColor(enumplayer.clr);

	g_VGuiSurface->DrawLine((screen_w / 2), screen_h, enumplayer.feet_pos.x, enumplayer.feet_pos.y);
	//	g_VGuiSurface->DrawLine((screen_w / 2)-1, screen_h, enumplayer.feet_pos.x-1, enumplayer.feet_pos.y);
	//	g_VGuiSurface->DrawLine((screen_w / 2)+1, screen_h, enumplayer.feet_pos.x+1, enumplayer.feet_pos.y);
}
void Visual::RenderBox() {

	g_VGuiSurface->DrawSetColor(enumplayer.clr);
	g_VGuiSurface->DrawOutlinedRect(enumplayer.bbox.left, enumplayer.bbox.top, enumplayer.bbox.right, enumplayer.bbox.bottom);
	//g_VGuiSurface->DrawSetColor(Color::Black);
	//g_VGuiSurface->DrawOutlinedRect(enumplayer.bbox.left - 1, enumplayer.bbox.top - 1, enumplayer.bbox.right + 1, enumplayer.bbox.bottom + 1);
	//g_VGuiSurface->DrawOutlinedRect(enumplayer.bbox.left + 1, enumplayer.bbox.top + 1, enumplayer.bbox.right - 1, enumplayer.bbox.bottom - 1);
}
void Visual::RenderBoneLine()
{
	

}

void Visual::RenderBones()
{
	g_VGuiSurface->DrawSetColor(enumplayer.clr);
	

	//脖子
	g_VGuiSurface->DrawLine(enumplayer.HEAD.ScreenPos.x,enumplayer.HEAD.ScreenPos.y, enumplayer.NECK.ScreenPos.x,enumplayer.NECK.ScreenPos.y);
	//左手
	g_VGuiSurface->DrawLine(enumplayer.NECK.ScreenPos.x,enumplayer.NECK.ScreenPos.y, enumplayer.LShoulder.ScreenPos.x,enumplayer.LShoulder.ScreenPos.y);
	g_VGuiSurface->DrawLine(enumplayer.LShoulder.ScreenPos.x,enumplayer.LShoulder.ScreenPos.y, enumplayer.LArm1.ScreenPos.x,enumplayer.LArm1.ScreenPos.y);
	g_VGuiSurface->DrawLine(enumplayer.LArm1.ScreenPos.x,enumplayer.LArm1.ScreenPos.y, enumplayer.LArm2.ScreenPos.x,enumplayer.LArm2.ScreenPos.y);

	//右手
	g_VGuiSurface->DrawLine(enumplayer.NECK.ScreenPos.x,enumplayer.NECK.ScreenPos.y, enumplayer.RShoulder.ScreenPos.x,enumplayer.RShoulder.ScreenPos.y);
	g_VGuiSurface->DrawLine(enumplayer.RShoulder.ScreenPos.x,enumplayer.RShoulder.ScreenPos.y, enumplayer.RArm1.ScreenPos.x,enumplayer.RArm1.ScreenPos.y);
	g_VGuiSurface->DrawLine(enumplayer.RArm1.ScreenPos.x,enumplayer.RArm1.ScreenPos.y, enumplayer.RArm2.ScreenPos.x,enumplayer.RArm2.ScreenPos.y);
	
	//BODY
	g_VGuiSurface->DrawLine(enumplayer.NECK.ScreenPos.x,enumplayer.NECK.ScreenPos.y, enumplayer.BODY6.ScreenPos.x,enumplayer.BODY6.ScreenPos.y);
	g_VGuiSurface->DrawLine(enumplayer.BODY6.ScreenPos.x,enumplayer.BODY6.ScreenPos.y, enumplayer.BODY5.ScreenPos.x,enumplayer.BODY5.ScreenPos.y);
	g_VGuiSurface->DrawLine(enumplayer.BODY5.ScreenPos.x,enumplayer.BODY5.ScreenPos.y, enumplayer.BODY4.ScreenPos.x,enumplayer.BODY4.ScreenPos.y);
	g_VGuiSurface->DrawLine(enumplayer.BODY4.ScreenPos.x,enumplayer.BODY4.ScreenPos.y, enumplayer.BODY3.ScreenPos.x,enumplayer.BODY3.ScreenPos.y);
	g_VGuiSurface->DrawLine(enumplayer.BODY3.ScreenPos.x,enumplayer.BODY3.ScreenPos.y, enumplayer.PELVIS.ScreenPos.x,enumplayer.PELVIS.ScreenPos.y);

	//左腿
	g_VGuiSurface->DrawLine(enumplayer.PELVIS.ScreenPos.x, enumplayer.PELVIS.ScreenPos.y, enumplayer.LLag1.ScreenPos.x, enumplayer.LLag1.ScreenPos.y);
	g_VGuiSurface->DrawLine(enumplayer.LLag1.ScreenPos.x, enumplayer.LLag1.ScreenPos.y, enumplayer.LLag2.ScreenPos.x, enumplayer.LLag2.ScreenPos.y);
	g_VGuiSurface->DrawLine(enumplayer.LLag2.ScreenPos.x, enumplayer.LLag2.ScreenPos.y, enumplayer.LLag3.ScreenPos.x, enumplayer.LLag3.ScreenPos.y);


	//右腿 
	g_VGuiSurface->DrawLine(enumplayer.PELVIS.ScreenPos.x, enumplayer.PELVIS.ScreenPos.y, enumplayer.RLag1.ScreenPos.x, enumplayer.RLag1.ScreenPos.y);
	g_VGuiSurface->DrawLine(enumplayer.RLag1.ScreenPos.x, enumplayer.RLag1.ScreenPos.y, enumplayer.RLag2.ScreenPos.x, enumplayer.RLag2.ScreenPos.y);
	g_VGuiSurface->DrawLine(enumplayer.RLag2.ScreenPos.x, enumplayer.RLag2.ScreenPos.y, enumplayer.RLag3.ScreenPos.x, enumplayer.RLag3.ScreenPos.y);


	//g_VGuiSurface->DrawLine(8, 7, Arrays.Entity[i].boneBase, m_WindowRectangle); // Neck
	//g_VGuiSurface->DrawLine(7, 41, Arrays.Entity[i].boneBase, m_WindowRectangle); // Left Shoulder
	//g_VGuiSurface->DrawLine(7, 11, Arrays.Entity[i].boneBase, m_WindowRectangle); // Right Shoulder
	//g_VGuiSurface->DrawLine(41, 42, Arrays.Entity[i].boneBase, m_WindowRectangle); // Left Arm 1
	//g_VGuiSurface->DrawLine(11, 12, Arrays.Entity[i].boneBase, m_WindowRectangle); // Right Arm 1
	//g_VGuiSurface->DrawLine(42, 43, Arrays.Entity[i].boneBase, m_WindowRectangle); // Left Arm 2
	//g_VGuiSurface->DrawLine(12, 13, Arrays.Entity[i].boneBase, m_WindowRectangle); // Right Arm 2
	//g_VGuiSurface->DrawLine(7, 6, Arrays.Entity[i].boneBase, m_WindowRectangle); // Upper Body
	//g_VGuiSurface->DrawLine(6, 5, Arrays.Entity[i].boneBase, m_WindowRectangle); // Middle Body
	//g_VGuiSurface->DrawLine(5, 3, Arrays.Entity[i].boneBase, m_WindowRectangle); // Lower Body
	//g_VGuiSurface->DrawLine(3, 77, Arrays.Entity[i].boneBase, m_WindowRectangle); // Left Pelvis
	//g_VGuiSurface->DrawLine(3, 70, Arrays.Entity[i].boneBase, m_WindowRectangle); // Right Pelvis
	//g_VGuiSurface->DrawLine(77, 78, Arrays.Entity[i].boneBase, m_WindowRectangle); // Left Leg
	//g_VGuiSurface->DrawLine(70, 71, Arrays.Entity[i].boneBase, m_WindowRectangle); // Right Leg
	//g_VGuiSurface->DrawLine(78, 79, Arrays.Entity[i].boneBase, m_WindowRectangle); // Left Shin
	//g_VGuiSurface->DrawLine(71, 72, Arrays.Entity[i].boneBase, m_WindowRectangle); // Right Shin

}



