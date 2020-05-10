#pragma once
#include "Actions/Action.h"
class To_Draw:public Action
{
public:
	To_Draw(ApplicationManager *);
	void ReadActionParameters();
	 void Execute() ;
	~To_Draw(void);
};

