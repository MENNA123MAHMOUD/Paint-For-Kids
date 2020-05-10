#include "Actions/Action.h"

class SaveAction :public Action
{ private:
	string l;
	
public :
	
	SaveAction(ApplicationManager *pApp);
	//to read  the file name
	virtual void ReadActionParameters();
	//to save the figures informations
	virtual void Execute();
};
