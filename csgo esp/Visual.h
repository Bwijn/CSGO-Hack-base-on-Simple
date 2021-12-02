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
	bool Begin(Ent* pl);

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
