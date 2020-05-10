#include "Actions/Action.h"

class Exit :public Action
{
 Exit(ApplicationManager *pApp);
 virtual void Execute();
 virtual void ReadActionParameters();

};