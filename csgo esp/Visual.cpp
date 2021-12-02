#include "pch.h"
Visual visual;

bool Visual::Begin(Ent* pl) {
	//localPlayer.ent = reinterpret_cast<Ent*>(entitylist->GetClientEntity(g_pIVEngineClient->GetLocalPlayer())); // TODO 替换为全局的localplayer 
		 //Player enumplayer 这个是临时的Player 对象 for 64 每循环一次就覆盖一次，充分利用

	enumplayer.ent = pl;
	enumplayer.isEnemy = localPlayer->TeamNum != enumplayer.ent->TeamNum;
	enumplayer.clr = enumplayer.isEnemy ? Color::Red : Color::Blue;

	auto head = pl->GetHeadPos();
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


	return true;

	//pl->origin.
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



