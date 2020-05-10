#pragma once
#include "Actions\Action.h"
#include"Figures\CFigure.h"

class SelectFigureAction : public Action {
	Point p1;
	CFigure* F;
public:
	SelectFigureAction();
	SelectFigureAction(ApplicationManager *pApp);
    
	//read action parameters
	virtual void ReadActionParameters();

	//execute the select action
	virtual void Execute() ;

	bool getfigure(int x,int y);






};