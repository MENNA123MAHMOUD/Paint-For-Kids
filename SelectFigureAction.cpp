#include "SelectFigureAction.h"

#include "ApplicationManager.h"
SelectFigureAction::SelectFigureAction(ApplicationManager *pApp):Action(pApp){F=NULL;}
void SelectFigureAction::ReadActionParameters() 
{	
	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
   
	
	pOut->PrintMessage("Select a figure");
	pIn->GetPointClicked(p1.x,p1.y);
	

}
void SelectFigureAction::Execute() 
{  
	if (pManager->get_sound())
	{
		sndPlaySound(TEXT("SOUNDS\\select.wav"), SND_FILENAME | SND_ASYNC);
	}
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	F=pManager->GetFigure(p1.x,p1.y);
	if(F!=NULL){
	F->SetSelected(true);
	pManager->setSelect(F);
	}
	else pOut->PrintMessage("No figure is selected");
	pManager->setSelect(F);
}

