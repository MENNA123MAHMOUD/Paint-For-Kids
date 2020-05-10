#pragma once
#include"Actions/Action.h"
#include"CopyAction.h"
#include"CutAction.h"
#include"Figures/CFigure.h"
class PasteAction :public Action {
	CFigure* p;
	Point p1;
public:

	PasteAction(ApplicationManager *pApp);

	//read action parameters
	virtual void ReadActionParameters();

	//execute the select action
	virtual void Execute();

};