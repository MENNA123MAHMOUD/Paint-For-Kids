#include "ExitAction.h"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"

Exit::Exit(ApplicationManager * pApp):Action(pApp)
{}

void Exit::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
}

//Execute the action
void Exit::Execute() 
{ 
	if (pManager->get_sound())
	{
		sndPlaySound(TEXT("SOUNDS\\exit.wav"), SND_FILENAME | SND_ASYNC);
	}
	if (pManager->get_sound())
	{
		sndPlaySound(TEXT("SOUNDS\\delete.wav"), SND_FILENAME | SND_ASYNC);
	}
	
	
}
