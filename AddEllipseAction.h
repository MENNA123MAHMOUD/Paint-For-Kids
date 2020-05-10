#pragma once
#include "Actions/Action.h"

//Add Ellipse Action class
class AddEllipseAction : public Action
{
private:
	Point P1, P2, P0; //Ellipse Corners
	GfxInfo RectGfxInfo;
public:
	AddEllipseAction(ApplicationManager *pApp);

	//Reads Ellipse parameters
	virtual void ReadActionParameters();

	//Add Ellipse to the ApplicationManager
	virtual void Execute();

};
