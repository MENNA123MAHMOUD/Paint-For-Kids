#include "AddRhombusAction.h"
#include "CRhombus.h"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"

AddRhombusAction::AddRhombusAction(ApplicationManager * pApp) :Action(pApp)
{}

void AddRhombusAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rhombus: Click at its center");
	Point P0;
	//Read the center of the rhombus

	pIn->GetPointClicked(P0.x, P0.y);
	while (P0.y < 220 || P0.y>430 || P0.x < 100 || P0.x>1150) {
		pOut->PrintMessage("YOU CANNOT DRAW HERE,  Click two points");
		pIn->GetPointClicked(P0.x, P0.y);
	}
	P1.x = P0.x;
	P1.y = P0.y + 170;
	P2.x = P0.x - 100;
	P2.y = P0.y;
	P3.x = P0.x;
	P3.y = P0.y - 170;
	P4.x = P0.x + 100;
	P4.y = P0.y;
	if (pManager->getcolored() == true) RectGfxInfo.isFilled = true;
	else
		RectGfxInfo.isFilled = false;	//default is not filled
	
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddRhombusAction::Execute()
{
	if (pManager->get_sound())
	{
		sndPlaySound(TEXT("SOUNDS\\rhombus.wav"), SND_FILENAME | SND_ASYNC);
	}
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	CRhombus *RH = new CRhombus(P1, P2, P3, P4, RectGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(RH);
}