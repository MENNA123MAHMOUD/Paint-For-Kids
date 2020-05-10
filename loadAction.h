#pragma once
#include "Actions/Action.h"

class loadAction :public Action
{ private :
	string l;

public:
	loadAction(ApplicationManager *pApp);
	//to read file name
	virtual void ReadActionParameters();
	// to load the figures
	virtual void Execute();
};