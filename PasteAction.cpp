#include"ApplicationManager.h"
#include"PasteAction.h"
PasteAction::PasteAction(ApplicationManager *pApp) :Action(pApp) {

}
//read action parameters
void PasteAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("choose a point to paste the copied  figure");
	pIn->GetPointClicked(p1.x, p1.y);
	pOut->ClearStatusBar();
}


//execute the select action
void PasteAction::Execute() {

	if (pManager->get_sound())
	{
		sndPlaySound(TEXT("SOUNDS\\paste.wav"), SND_FILENAME | SND_ASYNC);
	}
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (pManager->getclipboard() != NULL) {
		
			ReadActionParameters();
			pManager->setb(false);
			CFigure* f = pManager->getclipboard();
			p = f->createfig();
			p->setgraphics(pManager->getgfx());
			pManager->AddFigure(p);
			pManager->setclipboard(p);
			p->pstfig(p1.x, p1.y);
			pManager->deletegray();
			p->Draw(pOut);
			
		
	}
	else
		pOut->PrintMessage("you have to copy your figure first");
	
}