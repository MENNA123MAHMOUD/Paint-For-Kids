#pragma once
#include"Actions/Action.h"
#include"Figures/CFigure.h"
#include"SelectFigureAction.h"
class CopyAction :public Action {
	CFigure* c;
public:

	CopyAction(ApplicationManager *pApp);
	//read action parameters
	virtual void ReadActionParameters();

	//execute the select action
	virtual void Execute();

};