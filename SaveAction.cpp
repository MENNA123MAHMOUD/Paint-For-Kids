#include "SaveAction.h"
#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"

SaveAction::SaveAction(ApplicationManager * pApp) :Action(pApp)
{}

void SaveAction::ReadActionParameters()
{
	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("please enter the file name to save in");

	l = pIn->GetSrting(pOut);

	pOut->ClearStatusBar();

}


void SaveAction::Execute()
{
	if (pManager->get_sound())
	{
		sndPlaySound(TEXT("SOUNDS\\save.wav"), SND_FILENAME | SND_ASYNC);
	}
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	ofstream outfile(l + ".txt");
	color c = pOut->getCrntDrawColor();
	color c1 = pOut->getCrntFillColor();
	if (c == RED)
		outfile << "RED" << "    ";
	else if (c == WHITE)
		outfile << "WHITE" << "    ";
	else if (c == GREEN)
		outfile << "GREEN" << "    ";
	else if (c == BLUE)
		outfile << "BLUE" << "    ";
	else if (c == BLACK)
		outfile << "BLACK" << "    ";


	if (c1 == RED)
		outfile << "RED" << endl;
	else if (c1 == WHITE)
		outfile << "WHITE" << endl;
	else if (c1 == GREEN)
		outfile << "GREEN" << endl;
	else if (c1 == BLUE)
		outfile << "BLUE" << endl;
	else if (c1 == BLACK)
		outfile << "BLACK" << endl;
	else
		outfile << "NO_FILL" << endl;

	outfile << pManager->getfigcount() << endl;

	pManager->SaveAll(outfile);

	outfile.close();
}