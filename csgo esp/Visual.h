#pragma once
#include "pch.h"

class Visual
{
public:
	//Visual();
	//~Visual();
	void	RenderCrosshair();
	void RenderSnapline();
	void RenderBox();
	void RenderBoneLine();
	void RenderBones();
	bool Begin(Ent* pl);
	void RenderName();

	bool CreateFonts();
private:

};

extern Visual visual;

//Visual::Visual()
//{
//}
//
//Visual::~Visual()
//{
//}
