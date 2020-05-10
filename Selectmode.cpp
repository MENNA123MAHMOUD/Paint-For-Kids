#include "Selectmode.h"

#include "ApplicationManager.h"
Selectmode::Selectmode(ApplicationManager *pApp):Action(pApp){F=NULL;}
void Selectmode::ReadActionParameters() 
{	
	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	pIn->GetPointClicked(p1.x,p1.y);
	

}
void Selectmode::Execute() 
{  
	int x,y;
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	F=pManager->GetFigure(p1.x,p1.y);
	CFigure*t=pManager->getSelect();
	
	if(F!=NULL){
		F->SetSelected(true);
		if(t!=NULL&&t==F){
			F->SetSelected(false);
			F=NULL;
			 pOut->ClearStatusBar();
		}
		 if(t!=NULL){t->SetSelected(false);}
		pManager->setSelect(F);
		
	
}
	else { if(t!=NULL){t->SetSelected(false);} pOut->ClearStatusBar(); }
	

}

