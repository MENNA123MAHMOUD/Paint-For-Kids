 #include "AddEllipseAction.h"
#include "CEllipse.h"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"

AddEllipseAction::AddEllipseAction(ApplicationManager * pApp) :Action(pApp)
{}

void AddEllipseAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Ellipse: Click at its center");

	pIn->GetPointClicked(P0.x, P0.y);
	while (P0.y < 120 || P0.y>530 || P0.x < 100 || P0.x>1150) {
		pOut->PrintMessage("YOU CANNOT DRAW HERE,  Click one points");
		pIn->GetPointClicked(P0.x, P0.y);
	}
	P1.x = P0.x + 100;
	P1.y = P0.y + 70;
	P2.x = P0.x -100;
	P2.y = P0.y - 70;
	if (pManager->getcolored() == true) RectGfxInfo.isFilled = true;
	else
		RectGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddEllipseAction::Execute()
{
	if (pManager->get_sound())
	{
		sndPlaySound(TEXT("SOUNDS\\ellipse.wav"), SND_FILENAME | SND_ASYNC);
	}
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a Ellipse with the parameters read from the user
	CEllipse *C = new CEllipse(P1, P2, P0, RectGfxInfo);

	//Add the Ellipse to the list of figures
	pManager->AddFigure(C);
}