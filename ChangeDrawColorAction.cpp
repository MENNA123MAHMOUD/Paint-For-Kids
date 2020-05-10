#include "ChangeDrawColorAction.h"


#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"

ChangeDrawColorAction::ChangeDrawColorAction(ApplicationManager * pApp):Action(pApp)
{}

void ChangeDrawColorAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	

}


void ChangeDrawColorAction::Execute() 
{
	if (pManager->get_sound())
	{
		sndPlaySound(TEXT("SOUNDS\\draw_color.wav"), SND_FILENAME | SND_ASYNC);
	}
	ActionType ActType;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	CFigure*c=pManager->getSelect();
	pManager->setcolored(false);
	if(c!=NULL){
	pOut->PrintMessage("select a color");
	
	ActType=pIn->GetUserAction();
	switch(ActType){
	case sel_white:
		if (pManager->get_sound())
		{
			sndPlaySound(TEXT("SOUNDS\\white_color.wav"), SND_FILENAME | SND_ASYNC);
		}
		pOut->PrintMessage("white");
		c->ChngDrawClr(WHITE); 
		UI.DrawColor=WHITE;
		c->SetSelected(false);
		pManager->unselect();
		
		break;
    	case sel_black:
			if (pManager->get_sound())
			{
				sndPlaySound(TEXT("SOUNDS\\black_color.wav"), SND_FILENAME | SND_ASYNC);
			}
		pOut->PrintMessage("black");
		c->ChngDrawClr(BLACK);
		UI.DrawColor=BLACK;
		c->SetSelected(false);
		pManager->unselect();
		break;
	    case sel_blue:
			if (pManager->get_sound())
			{
				sndPlaySound(TEXT("SOUNDS\\blueColor.wav"), SND_FILENAME | SND_ASYNC);
			}
		pOut->PrintMessage("Blue");
			c->ChngDrawClr(BLUE); 
		c->ChngDrawClr(BLUE);
		UI.DrawColor=BLUE;
		c->SetSelected(false);
		pManager->unselect();
		break;
		case sel_red:
			if (pManager->get_sound())
			{
				sndPlaySound(TEXT("SOUNDS\\red_color.wav"), SND_FILENAME | SND_ASYNC);
			}
		pOut->PrintMessage("Red");
			c->ChngDrawClr(RED); 
		c->ChngDrawClr(RED);
		UI.DrawColor=RED;
		c->SetSelected(false);
		pManager->unselect();
		break;
		case sel_green:
			if (pManager->get_sound())
			{
				sndPlaySound(TEXT("SOUNDS\\green.wav"), SND_FILENAME | SND_ASYNC);
			}
			pOut->PrintMessage("Green");
			c->ChngDrawClr(GREEN); 
		c->ChngDrawClr(GREEN);
		UI.DrawColor=GREEN;
		c->SetSelected(false);
		pManager->unselect();
		break;
	
	}
} else{pOut->PrintMessage("select a figure first");}
}