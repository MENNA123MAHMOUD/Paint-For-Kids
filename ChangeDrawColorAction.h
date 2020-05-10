#include "Actions\Action.h"


class ChangeDrawColorAction: public Action
{

	
public:
	
	ChangeDrawColorAction(ApplicationManager *pApp);

	
	virtual void ReadActionParameters();
	

	virtual void Execute() ;
	
};