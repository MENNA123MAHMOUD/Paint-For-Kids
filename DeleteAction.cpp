#include "DeleteAction.h"
#include "Figures\CRectangle.h"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"

DeleteAction::DeleteAction(ApplicationManager * pApp):Action(pApp)
{}

void DeleteAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Input* pIn = pManager->GetInput();
}

//Execute the action
void DeleteAction::Execute() 
{ 
	if (pManager->get_sound())
	{
		sndPlaySound(TEXT("SOUNDS\\delete.wav"), SND_FILENAME | SND_ASYNC);
	}
	
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("you delete this figure");
	pManager->deletefig();
	
}
