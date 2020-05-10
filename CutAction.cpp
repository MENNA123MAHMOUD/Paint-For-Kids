#include"CutAction.h"
#include"ApplicationManager.h"
#include"Cline.h"
CutAction::CutAction(ApplicationManager *pApp) :Action(pApp) {

}
//read action parameters
void CutAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("your figure is cutted ");
}

//execute the cut action
void CutAction::Execute() {
	if (pManager->get_sound())
	{
		sndPlaySound(TEXT("SOUNDS\\cut.wav"), SND_FILENAME | SND_ASYNC);
	}
	Output* pOut = pManager->GetOutput();
	CFigure*test = pManager->getSelect();
	if(test!=NULL)test->SetSelected(false);
	if (pManager->getSelect() != NULL) {
		if (!(pManager->getb())) {
			pManager->setclipboard(pManager->getSelect());
			CFigure* fig = pManager->getclipboard();
			pManager->setgfx(fig->getgraphics());
			Cline* l = dynamic_cast<Cline*>(fig);
			if (l == NULL) {
				(pManager->getclipboard())->ChngFillClr(GREY);
				(pManager->getclipboard())->ChngDrawClr(GREY);
			}
			else {
				(pManager->getclipboard())->ChngDrawClr(GREY);
			}
			pManager->unselect();
			pManager->setb(true);
			ReadActionParameters();
		}
		else {
			pManager->overwritten();
			pManager->setclipboard(pManager->getSelect());
			CFigure* fig = pManager->getclipboard();
			pManager->setgfx(fig->getgraphics());
			Cline* l = dynamic_cast<Cline*>(fig);
			if (l == NULL) {
				(pManager->getclipboard())->ChngFillClr(GREY);
				(pManager->getclipboard())->ChngDrawClr(GREY);
			}
			else {
				(pManager->getclipboard())->ChngDrawClr(GREY);
			}
			pManager->unselect();
			pManager->setb(true);
			ReadActionParameters();
		}
	}
	else
		pOut->PrintMessage("you should select a figure first ");

}