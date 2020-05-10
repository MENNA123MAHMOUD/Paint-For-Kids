#pragma once
#include "Actions/Action.h"
class To_Play :public Action
{
public:
	To_Play(ApplicationManager *);
	void ReadActionParameters();
    void Execute();
	~To_Play(void);
};

