# pragma once
#include "loadAction.h"
#include "ApplicationManager.h"
#include "Figures\CRectangle.h"
#include "CEllipse.h"
#include "Cline.h"
#include "CRhombus.h"
#include "Ctriangle.h"
#include "GUI\input.h"
#include "GUI\Output.h"

loadAction::loadAction(ApplicationManager *pApp):Action(pApp)
{}
void loadAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("please enter the file name you already saved");

	l= pIn->GetSrting(pOut);
	pOut->ClearStatusBar();


}
void loadAction::Execute()
{
	if (pManager->get_sound())
	{
		sndPlaySound(TEXT("SOUNDS\\load.wav"), SND_FILENAME | SND_ASYNC);
	}
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	ifstream infile(l + ".txt");
	if (infile.is_open())
	{
		int number;
		string drawcolor, fillcolor;
		infile >> drawcolor >> fillcolor >> number;
		if (drawcolor == "BLUE")
			UI.DrawColor = BLUE;
		else if (drawcolor == "RED")
			UI.DrawColor = RED;
		else if (drawcolor == "BLACK")
			UI.DrawColor = BLACK;
		else if (drawcolor == "GREEN")
			UI.DrawColor = GREEN;
		else if (drawcolor == "WHITE")
			UI.DrawColor = WHITE;

		if (fillcolor == "BLUE")
			UI.FillColor = BLUE;
		else if (fillcolor == "RED")
			UI.FillColor = RED;
		else if (fillcolor == "BLACK")
			UI.FillColor = BLACK;
		else if (fillcolor == "GREEN")
			UI.FillColor = GREEN;
		else if (fillcolor == "WHITE")
			UI.FillColor = WHITE;
		else
			UI.FillColor = GREEN;

			CFigure *ptr;
			string l;
			infile >> l;
			if (l == "RECT")
			{
				ptr = new CRectangle;
				ptr->Load(infile);
			}
			else if (l == "LINE")
			{
				ptr = new Cline;
				ptr->Load(infile);
			}
			else  if (l == "TRING")
			{
				ptr = new Ctriangle;
				ptr->Load(infile);
			}
			else if (l == "RHOMBUS")
			{
				ptr = new CRhombus;
				ptr->Load(infile);
			}
			else if (l == "ELLIPSE")
			{
				ptr = new CEllipse;
				ptr->Load(infile);
			}

			while (!infile.eof())
			{
				pManager->AddFigure(ptr);
				infile >> l;
				if (l == "RECT")
				{
					ptr = new CRectangle;
					ptr->Load(infile);
				}
				else if (l == "LINE")
				{
					ptr = new Cline;
					ptr->Load(infile);
				}
				else  if (l == "TRING")
				{
					ptr = new Ctriangle;
					ptr->Load(infile);
				}
				else if (l == "RHOMBUS")
				{
					ptr = new CRhombus;
					ptr->Load(infile);
				}
				else if (l == "ELLIPSE")
				{
					ptr = new CEllipse;
					ptr->Load(infile);
				}
			}

		


	}
	else
	{
		
		
		this->Execute();
	}

	infile.close();
}