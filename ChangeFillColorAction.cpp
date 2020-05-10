#pragma once
#include "ChangeFillColorAction.h"

#include "Cline.h"
#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"

ChangeFillColorAction::ChangeFillColorAction(ApplicationManager * pApp):Action(pApp)
{}

void ChangeFillColorAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	

}


void ChangeFillColorAction::Execute() 
{
	if (pManager->get_sound())
	{
		sndPlaySound(TEXT("SOUNDS\\filled_color.wav"), SND_FILENAME | SND_ASYNC);
	}
	ActionType ActType;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	CFigure*c=pManager->getSelect();
	Cline*t=dynamic_cast<Cline*>(c);
	if(c!=NULL){
	if(t==NULL){
	pManager->setcolored(true);
	pOut->PrintMessage("select a color");
	
	ActType=pIn->GetUserAction();
	switch(ActType){
	case sel_white:
		if (pManager->get_sound())
		{
			sndPlaySound(TEXT("SOUNDS\\white_color.wav"), SND_FILENAME | SND_ASYNC);
		}
		pOut->PrintMessage("white");
		c->ChngFillClr(WHITE); 
		UI.FillColor=WHITE;
		c->SetSelected(false);
		pManager->unselect();
		
		break;
    	case sel_black:
			if (pManager->get_sound())
			{
				sndPlaySound(TEXT("SOUNDS\\black_color.wav"), SND_FILENAME | SND_ASYNC);
			}
		pOut->PrintMessage("black");
		c->ChngFillClr(BLACK);
		UI.FillColor=BLACK;
		c->SetSelected(false);
		pManager->unselect();
		break;
	    case sel_blue:
			if (pManager->get_sound())
			{
				sndPlaySound(TEXT("SOUNDS\\blueColor.wav"), SND_FILENAME | SND_ASYNC);
			}
		pOut->PrintMessage("Blue");
			c->ChngFillClr(BLUE); 
		UI.FillColor=BLUE;
		c->SetSelected(false);
		pManager->unselect();
		break;
		case sel_red:
			if (pManager->get_sound())
			{
				sndPlaySound(TEXT("SOUNDS\\red_color.wav"), SND_FILENAME | SND_ASYNC);
			}
			pOut->PrintMessage("Red");
			c->ChngFillClr(RED); 
		UI.FillColor=RED;
		c->SetSelected(false);
		pManager->unselect();
		break;
		case sel_green:
			if (pManager->get_sound())
			{
				sndPlaySound(TEXT("SOUNDS\\green.wav"), SND_FILENAME | SND_ASYNC);
			}
			pOut->PrintMessage("Green");
			c->ChngFillClr(GREEN); 
		UI.FillColor=GREEN;
		c->SetSelected(false);
		pManager->unselect();
		break;
	
	}
	}
	else{pOut->PrintMessage("Line can't be Filled");}
}
	else{pOut->PrintMessage("Select a figure first");}
}