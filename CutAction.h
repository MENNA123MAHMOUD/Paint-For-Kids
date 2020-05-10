#pragma once
#include"Actions/Action.h"
#include"Figures/CFigure.h"
#include"SelectFigureAction.h"
class CutAction :public Action {
	CFigure* cut;
public:

	CutAction(ApplicationManager *pApp);
	//read action parameters
	virtual void ReadActionParameters();

	//execute the cut action
	virtual void Execute();

};