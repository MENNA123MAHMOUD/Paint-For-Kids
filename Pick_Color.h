#pragma once
#include<cstdlib>
#include<ctime>
#include "Actions/Action.h"
class Pick_Color:public Action
{
public:
	Pick_Color(ApplicationManager *);
	void ReadActionParameters();
	 void Execute() ;
	~Pick_Color(void);
};

