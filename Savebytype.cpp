#include "Savebytype.h"
#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"

Savebytype::Savebytype(ApplicationManager * pApp):Action(pApp)
{}
void Savebytype::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("please enter the file name to save in");

	l = pIn->GetSrting(pOut);

	pOut->ClearStatusBar();


	pOut->PrintMessage("please choose the figure type you want to save from the icons");

	type = pIn->GetUserAction();
	pOut->ClearStatusBar();

}
void Savebytype::Execute()
{ 
	if (pManager->get_sound())
	{
		sndPlaySound(TEXT("SOUNDS\\save_type.wav"), SND_FILENAME | SND_ASYNC);
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


	if (type == DRAW_LINE)
		pManager->savebytype(outfile,type);
	else if (type == DRAW_RECT)
		pManager->savebytype(outfile, type);
	else if (type==DRAW_RHOMBUS)
		pManager->savebytype(outfile, type);
	else if (type == DRAW_ELLIPSE)
		pManager->savebytype(outfile, type);
	else if (type == DRAW_TRI)
		pManager->savebytype(outfile, type);
	else
	{
		this->Execute();

	}
	outfile.close();
}