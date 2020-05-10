#include "To_Play.h"
#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"

To_Play::To_Play(ApplicationManager * pApp):Action(pApp)
{
	
}
void To_Play::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


}
void To_Play::Execute(){
	if(pManager->get_sound())
	{
	sndPlaySound(TEXT("SOUNDS\\play.wav"),SND_FILENAME|SND_ASYNC);
	}
	pManager->copy_figs();
	ReadActionParameters();
		Output* pOut = pManager->GetOutput();
	    Input* pIn = pManager->GetInput();		
		        pOut->PrintMessage("Action: change mode, creating Design tool bar");
				pOut->ClearToolBar();
				pOut->CreatePlayToolBar();

}
To_Play::~To_Play(){
}


