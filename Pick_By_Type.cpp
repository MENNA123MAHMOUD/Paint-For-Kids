#include "Pick_By_Type.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include<cstdlib>
#include<ctime>
#include<string>
Pick_By_Type::Pick_By_Type(ApplicationManager * pApp): Action(pApp)
{
}
void Pick_By_Type::ReadActionParameters(){
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
}
void Pick_By_Type::Execute(){
	//pManager->copy_figs();
	if(pManager->get_sound())
	{
	sndPlaySound(TEXT("SOUNDS\\pick_type.wav"),SND_FILENAME|SND_ASYNC);
	}

	pManager->recopy_figlist();
	pManager->UpdateInterface();
	int x=0 ;
	int y=0;                           //(x,y)the location of the click of the user
	long long right_ans=0;                  //equal to the number of the chosen shapes
	long long wrong_ans=0;
	ReadActionParameters();        //function to read action from user  
		Output* pOut = pManager->GetOutput();    
	    Input* pIn = pManager->GetInput();	
		int arr[5];
		pManager->get_number_of_shapes(arr);  //function to define the number of evrey shape 
		int Shape_Num;
		do{
			Shape_Num=rand()%4;
		}
	while (arr[Shape_Num]==0);
	
	if (Shape_Num==0){
		pOut->PrintMessage("choose all of the lines");
		//right_ans=arr[0];
		do{
		
		pIn->GetPointClicked(x,y);
		CFigure* shape=pManager->GetFigure(x,y);
			if(shape!=NULL){
				Cline* cli=dynamic_cast<Cline*>(shape);
			
			if(cli!=NULL){
				arr[0]--;
				pManager->setSelect(cli);
				pManager->deletefig();
		    //pManager->delete_shapes();
			pOut->ClearDrawArea();
			pManager->UpdateInterface();
				
	right_ans++;
			}
			else{
				wrong_ans++;
			}
				}
			else if(y>=0 &&y<UI.ToolBarHeight){
				arr[Shape_Num]=0;
			}
		}
	
		while(arr[0]!=0);
	}
				else if (Shape_Num==1){
					pOut->PrintMessage("choose all of the rectangles");
		//right_ans=arr[1];
		
		do{
			pIn->GetPointClicked(x,y);
		CFigure* shape=pManager->GetFigure(x,y);
			if(shape!=NULL){
			CRectangle* crec=dynamic_cast<CRectangle*>(shape);
			if(crec!=NULL){
				pManager->setSelect(crec);
				pManager->deletefig();
				pManager->UpdateInterface();
				arr[Shape_Num]--;
				right_ans++;
			}
			else{
				wrong_ans++;
			}
				}
			else if(y>=0 &&y<UI.ToolBarHeight){
				arr[Shape_Num]=0;
			}
				}
		while(arr[1]!=0);
				}
				else if (Shape_Num==2){
					pOut->PrintMessage("choose all of the rhombuses");
		//right_ans=arr[2];
		
		do{
			pIn->GetPointClicked(x,y);
		CFigure* shape=pManager->GetFigure(x,y);
			if(shape!=NULL){
			CRhombus* crhom=dynamic_cast<CRhombus*>(shape);
			if(crhom!=NULL){
				pManager->setSelect(crhom);
				pManager->deletefig();
				pManager->UpdateInterface();
				arr[Shape_Num]--;
				right_ans++;
			}
			else{
				wrong_ans++;
			}
			}
			else if(y>=0 &&y<UI.ToolBarHeight){
				arr[Shape_Num]=0;
			}
				}
			while(arr[2]!=0);
				}
				else if (Shape_Num==3){
					pOut->PrintMessage("choose all of the ellipses");
		//right_ans=arr[3];
		
		do{
			pIn->GetPointClicked(x,y);
		CFigure* shape=pManager->GetFigure(x,y);
			if(shape!=NULL){
			CEllipse* cell=dynamic_cast<CEllipse*>(shape);
			if(cell!=NULL){
				pManager->setSelect(cell);
				pManager->deletefig();
				pManager->UpdateInterface();
				arr[Shape_Num]--;
				right_ans++;
			}
			else{
				wrong_ans++;
			}
				}
			else if(y>=0 &&y<UI.ToolBarHeight){
				arr[Shape_Num]=0;
				}
			}
			while(arr[3]!=0);
				}
				else if (Shape_Num==4){
					pOut->PrintMessage("choose all of the triangles");
	//	right_ans=arr[4];
		pIn->GetPointClicked(x,y);
		do{
			pIn->GetPointClicked(x,y);
		CFigure* shape=pManager->GetFigure(x,y);
			if(shape!=NULL){
			Ctriangle* ctri=dynamic_cast<Ctriangle*>(shape);
			if(ctri!=NULL){
				pManager->setSelect(ctri);
				pManager->deletefig();
				pManager->UpdateInterface();
				arr[Shape_Num]--;
				right_ans++;
			}
			else{
				wrong_ans++;
			}
				}
			else if(y>=0 &&y<UI.ToolBarHeight){
				arr[Shape_Num]=0;
			}
			}
			while(arr[4]!=0);
				}
				
					std::string ra = std::to_string(right_ans);
					std::string wa= std:: to_string(wrong_ans);
				pOut->PrintMessage("right answers:"+ra+"wrong answers: "+wa);
				
		
				}
Pick_By_Type::~Pick_By_Type(void)
{
}
