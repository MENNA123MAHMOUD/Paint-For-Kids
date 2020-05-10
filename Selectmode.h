#pragma once
#include "Actions\Action.h"
#include"Figures\CFigure.h"

class Selectmode : public Action {
	Point p1;
	CFigure* F;
public:
	Selectmode();
	Selectmode(ApplicationManager *pApp);
    
	//read action parameters
	virtual void ReadActionParameters();

	//execute the select action
	virtual void Execute() ;

	bool getfigure(int x,int y);






};