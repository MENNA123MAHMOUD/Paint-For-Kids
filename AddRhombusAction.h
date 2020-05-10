#pragma once
#include "Actions\Action.h"

//Add Triangle Action class
class AddRhombusAction : public Action
{
private:
	Point P1, P2, P3, P4; //Triangle Corners
	GfxInfo RectGfxInfo;
public:
	AddRhombusAction(ApplicationManager *pApp);

	//Reads triangle parameters
	virtual void ReadActionParameters();

	//Add triangle to the ApplicationManager
	virtual void Execute();

};