#include "AddTriangleAction.h"
#include "Ctriangle.h"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"

AddTriangleAction::AddTriangleAction(ApplicationManager * pApp) :Action(pApp)
{}

void AddTriangleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first corner");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("New Triangle: Click at third corner");

	//Read 3rd corner and store in point P3
	pIn->GetPointClicked(P3.x, P3.y);

	if (pManager->getcolored() == true) RectGfxInfo.isFilled = true;
	else
		RectGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddTriangleAction::Execute()
{
	if (pManager->get_sound())
	{
		sndPlaySound(TEXT("SOUNDS\\riangle.wav"), SND_FILENAME | SND_ASYNC);
	}
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	Ctriangle *T = new Ctriangle(P1, P2, P3, RectGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(T);
}