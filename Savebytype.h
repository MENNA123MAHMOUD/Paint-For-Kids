#include "Actions/Action.h"
class Savebytype : public Action
{ 
	string l;
	ActionType type;
public:
	Savebytype(ApplicationManager *pApp);
	//to read the user action
	virtual void ReadActionParameters();
	//to save figures by type
	virtual void Execute();
};