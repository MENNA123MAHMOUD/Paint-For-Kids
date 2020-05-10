#include"CopyAction.h"
#include"ApplicationManager.h"
CopyAction::CopyAction(ApplicationManager *pApp) :Action(pApp) {

}
//read action parameters
void CopyAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("your figure is copied ");
}

//execute the copy action
void CopyAction::Execute() {
	if (pManager->get_sound())
	{
		sndPlaySound(TEXT("SOUNDS\\copy.wav"), SND_FILENAME | SND_ASYNC);
	}
	Output* pOut = pManager->GetOutput();
	if (pManager->getSelect() != NULL) {
		if (!(pManager->getb())) {
			pManager->setclipboard(pManager->getSelect());
			CFigure* fig = pManager->getclipboard();
			pManager->setgfx(fig->getgraphics());
			ReadActionParameters();
			pManager->setb(true);
			pManager->unselect();
		}
		else {
			pManager->overwritten();
			pManager->setclipboard(pManager->getSelect());
			CFigure* fig = pManager->getclipboard();
			pManager->setgfx(fig->getgraphics());
			ReadActionParameters();
			pManager->setb(true);
			pManager->unselect();
		}
	}
	else
		pOut->PrintMessage("you should select a figure first ");

	}
