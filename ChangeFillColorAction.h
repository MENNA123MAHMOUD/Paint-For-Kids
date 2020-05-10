#include "Actions\Action.h"


class ChangeFillColorAction: public Action
{

	
public:
	
	ChangeFillColorAction(ApplicationManager *pApp);

	
	virtual void ReadActionParameters();
	

	virtual void Execute() ;
	
};