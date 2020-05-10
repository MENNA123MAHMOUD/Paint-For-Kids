#include "Actions\Action.h"

class DeleteAction: public Action
{
private:
	
public:
	DeleteAction(ApplicationManager *pApp);

	
	virtual void ReadActionParameters();

	virtual void Execute() ;
	
};