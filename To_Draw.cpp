#include "To_Draw.h"
#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"


To_Draw::To_Draw(ApplicationManager * pApp):Action(pApp)
{
}
void To_Draw::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


}
void To_Draw::Execute(){
	if(pManager->get_sound())
	{
	sndPlaySound(TEXT("SOUNDS\\to_draw.wav"),SND_FILENAME|SND_ASYNC);
	}
	pManager->recopy_figlist();
    pManager->UpdateInterface();
	ReadActionParameters();
		Output* pOut = pManager->GetOutput();
	    Input* pIn = pManager->GetInput();		
		        pOut->PrintMessage("Action: To Draw, ");
				pOut->ClearToolBar();
				pOut->ClearDrawArea();
				pOut->CreateDrawToolBar();

}

To_Draw::~To_Draw(void)
{
}
