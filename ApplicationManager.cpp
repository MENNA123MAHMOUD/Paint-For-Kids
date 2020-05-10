#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include"AddTriangleAction.h"
#include"AddLineAction.h"
#include"CopyAction.h"
#include"PasteAction.h"
#include"AddRhombusAction.h"
#include"AddEllipseAction.h"
#include "DeleteAction.h"
#include"Selectmode.h"
#include "SaveAction.h"
#include "loadAction.h"
#include "Savebytype.h"
#include "Ctriangle.h"
#include "CEllipse.h"
#include "Cline.h"
#include "CRhombus.h"
#include"SelectFigureAction.h"
#include"Selectmode.h"
#include "Figures/CRectangle.h"
#include"ChangeDrawColorAction.h"
#include"ChangeFillColorAction.h"
#include"To_Play.h"
#include"To_Draw.h"
#include"Pick_Color.h"
#include"Pick_By_Type.h"
//Constructor
ApplicationManager::ApplicationManager()
{
	sound = false;
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	SelectedFig =NULL;
	colortest = false;
	Clipboard =NULL;
	FigCount = 0;
	b = false;
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;
		case DRAW_TRI:
			pAct = new AddTriangleAction(this);
			break;
		case TO_SEL:
			pAct = new SelectFigureAction(this);
			break;
		case TO_COPY:
				pAct = new CopyAction(this);
				break;
		case TO_CUT:
			    pAct = new CutAction(this);
			    break;
		case TO_PASTE:
				pAct = new PasteAction(this);
				break;
		case DEL:
			pAct = new DeleteAction(this);
			break;
		case DRAW_LINE:
			pAct = new AddLineAction(this);
			break;
			///create AddLineAction here
		case DRAW_RHOMBUS:
			pAct = new AddRhombusAction(this);
			break;
		case DRAW_ELLIPSE:
			pAct = new AddEllipseAction(this);
			break;
		case SAVE:
			pAct = new SaveAction(this);
			break;
		case SAVE_BY_TYPE:
			pAct = new Savebytype(this);
			break;
		case LOAD:
			pAct = new loadAction(this);
			break;
		case CHNG_DRAW_CLR:
			pAct = new ChangeDrawColorAction(this);
			break;
		case CHNG_FILL_CLR:
			pAct = new ChangeFillColorAction(this);
			break;
		case DRAWING_AREA:
			pAct = new Selectmode(this);
			break;
		case TO_PLAY:
			pAct = new To_Play(this);
			break;
		case  TO_DRAW:
			pAct = new To_Draw(this);
			break;
		case PICK_TYPE:
			pAct = new Pick_By_Type(this);
			break;
		case PICK_COLOR:
			pAct = new Pick_Color(this);
			break;
		case SOUNDON:
			sound = true;
			break;
		case SOUNDOFF:
			sound = false;
			break;


		case EXIT:
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
	FigList[FigCount - 1]->setid(FigCount);
}
void ApplicationManager::setclipboard(CFigure* c){
	Clipboard = c ;
}
CFigure* ApplicationManager::getclipboard() {
	return Clipboard;
}
void ApplicationManager::setSelect(CFigure* c) {
	SelectedFig = c;
}
CFigure* ApplicationManager::getSelect() {
	return SelectedFig;
}
int ApplicationManager::getfigcount() {
	return FigCount;
}
void ApplicationManager::setgfx(GfxInfo g) {
	gfx = g;
}
GfxInfo ApplicationManager::getgfx() {
	return gfx;
}
void ApplicationManager::setb(bool b2) {
	b = b2;
}
bool ApplicationManager::getb() {
	return b;
}
/*CFigure* ApplicationManager::get() {
	CFigure* p[200];
	for (int i = 0; i < FigCount; i++) {
		p[i] = FigList[i];
	}
	return *p;
}*/
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::setcolored(bool t) { colortest = t; }
bool ApplicationManager::getcolored() { return colortest; }
int c;
CFigure *ApplicationManager::GetFigure(int x, int y)
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL

	for (int i = FigCount - 1; i >= 0; i--) {

		if (FigList[i]->getfigure(x, y)) {
			FigList[i]->printinfo(pOut); c = i;
			return FigList[i];
		}

	}

	for (int i = FigCount - 1; i >= 0; i--) {
		{FigList[i]->SetSelected(false); SelectedFig = NULL; }
	}

	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}
void ApplicationManager::deletefig() {
	int k = 0;
	if (SelectedFig == NULL) { pOut->PrintMessage("you should select figure first"); }
	else {
		for (int i = 0; i < FigCount; i++) {
			if (FigList[i] == SelectedFig) {
				for (int j = i; j < FigCount - 1; j++) {
					FigList[j] = FigList[j + 1];
				}  
				FigCount--;
			}
		}
		unselect();
	}
	for (int i = 0; i < FigCount; i++) {
		FigList[i]->setid(k + 1); k++;
	}
}
void ApplicationManager::deletegray() {
	 
    for (int i = 0; i < FigCount; i++) {
			if ( FigList[i]->getDRAWClr() == GRAY) {
				FigList[i] = FigList[FigCount-1];
				FigList[FigCount-1] = NULL;

				FigCount--;
			}
		}
		unselect();
	int k=0;
	for (int j = 0; j < FigCount; j++) {
		FigList[j]->setid(k+1);
	k++;
	}
}
void ApplicationManager::overwritten() {
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->getDRAWClr() == GRAY) {
			FigList[i]->setgraphics(getgfx());
		}
	}
}
void ApplicationManager::SaveAll(ofstream & out)
{
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Save(out);
}
void ApplicationManager::savebytype(ofstream & out, ActionType type)
{
	int c = 0;
	for (int i = 0; i < FigCount; i++)
	{

		if (type == DRAW_LINE)
		{
			Cline * pt = dynamic_cast<Cline*>(FigList[i]);
			if (pt != NULL)
				c++;
		}
		else if (type == DRAW_RECT)
		{
			CRectangle * pt = dynamic_cast<CRectangle*>(FigList[i]);
			if (pt != NULL)
				c++;

		}
		else if (type == DRAW_ELLIPSE)
		{
			CEllipse * pt = dynamic_cast<CEllipse*>(FigList[i]);
			if (pt != NULL)
				c++;
		}
		else if (type == DRAW_RHOMBUS)
		{
			CRhombus * pt = dynamic_cast<CRhombus*>(FigList[i]);
			if (pt != NULL)
				c++;
		}
		else if (type == DRAW_TRI)
		{
			Ctriangle * pt = dynamic_cast<Ctriangle*>(FigList[i]);
			if (pt != NULL)
				c++;
		}
	}

	out << c << endl;


	for (int i = 0; i < FigCount; i++)
	{
		if (type == DRAW_LINE)
		{
			Cline * pt = dynamic_cast<Cline*>(FigList[i]);
			if (pt != NULL)
				pt->Save(out);
		}
		else if (type == DRAW_RECT)
		{
			CRectangle * pt = dynamic_cast<CRectangle*>(FigList[i]);
			if (pt != NULL)
				pt->Save(out);

		}
		else if (type == DRAW_ELLIPSE)
		{
			CEllipse * pt = dynamic_cast<CEllipse*>(FigList[i]);
			if (pt != NULL)
				pt->Save(out);
		}
		else if (type == DRAW_RHOMBUS)
		{
			CRhombus * pt = dynamic_cast<CRhombus*>(FigList[i]);
			if (pt != NULL)
				pt->Save(out);
		}
		else if (type == DRAW_TRI)
		{
			Ctriangle * pt = dynamic_cast<Ctriangle*>(FigList[i]);
			if (pt != NULL)
				pt->Save(out);
		}
	}

}
void ApplicationManager::unselect() {
	SelectedFig = NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pOut->ClearDrawArea();
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);	
	
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
void ApplicationManager::get_number_of_shapes(int *NOSh) {
	for (int i = 0; i < 5; i++)
		NOSh[i] = 0;
	for (int i = 0; i < FigCount; i++) {

		Cline*cl = dynamic_cast<Cline*>(FigList[i]);
		if (cl != NULL)NOSh[0]++;
		else {
			CRectangle * cr = dynamic_cast<CRectangle*>(FigList[i]);
			if (cr != NULL)NOSh[1]++;
			else {
				CRhombus*crh = dynamic_cast<CRhombus*>(FigList[i]);
				if (crh != NULL)NOSh[2]++;
				else {
					CEllipse*ce = dynamic_cast<CEllipse*>(FigList[i]);
					if (ce != NULL)NOSh[3]++;
					else {
						Ctriangle*ct = dynamic_cast<Ctriangle*>(FigList[i]);
						if (ct != NULL)NOSh[4]++;
					}

				}
			}


		}
	}
}
void ApplicationManager::copy_figs() {
	FigCountCopy = FigCount;
	for (int i = 0; i < FigCount; i++) {
		CopyFigList[i] = FigList[i];
	}

}
void ApplicationManager::recopy_figlist() {
	FigCount = FigCountCopy;
	for (int i = 0; i < FigCountCopy; i++) {
		FigList[i] = CopyFigList[i];

	}
	UpdateInterface();
}
void ApplicationManager::get_number_of_colored_shapes(int NOCSH[]) {
	for (int i = 0; i < 5; i++)
		NOCSH[i] = 0;

	for (int i = 0; i < FigCount; i++) {
		CFigure* S = FigList[i];
		setSelect(S);
		getSelect();
		if (S->get_shape_color() == WHITE || S->get_filled_color() == WHITE) {
			NOCSH[0]++;
		}
		else if (S->get_shape_color() == BLACK || S->get_filled_color() == BLACK) {


			NOCSH[1]++;
		}
		else if (S->get_shape_color() == RED || S->get_filled_color() == RED) {


			NOCSH[2]++;
		}
		else if (S->get_shape_color() == BLUE || S->get_filled_color() == BLUE) {


			NOCSH[3]++;
		}
		else if (S->get_shape_color() == GREEN || S->get_filled_color() == GREEN) {


			NOCSH[4]++;
		}
	}

}
bool ApplicationManager::get_sound() {
	return sound;
}


////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
