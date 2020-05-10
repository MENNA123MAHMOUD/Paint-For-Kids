#include "Pick_Color.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include <iostream>
Pick_Color::Pick_Color(ApplicationManager * pApp):Action(pApp)
{
}


void Pick_Color:: ReadActionParameters(){
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
}
void Pick_Color:: Execute(){
	if(pManager->get_sound())
	{
	sndPlaySound(TEXT("SOUNDS\\pick_color.wav"),SND_FILENAME|SND_ASYNC);
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
	//	pOut->PrintMessage("it get into");
		

		int arr[5];
		pManager->get_number_of_colored_shapes(arr); pOut->PrintMessage("it get into"); //function to define the number of evrey shape 
		int Shape_colored_Num;std::cout<<arr[0];
		do{
			Shape_colored_Num=rand()%4;
		}
	while (arr[Shape_colored_Num]==0);
	
	if (Shape_colored_Num==0){
		pOut->PrintMessage("choose all of the white shapes");
	//	right_ans=arr[0];
		do{
		
		pIn->GetPointClicked(x,y);
		CFigure* SH=pManager->GetFigure(x,y);
		 if(y>=0 &&y<UI.ToolBarHeight){
				arr[Shape_colored_Num]=0;
		 }
	//	pManager->setselected(SH);
		 else	if(SH->get_shape_color()==WHITE||SH->get_filled_color()==WHITE){		
				
				arr[0]--;
				pManager->setSelect(SH);
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
	
		while(arr[0]!=0);
	}
	///////////////////////////////////////////////////////////////////////////////
	if (Shape_colored_Num==1){
		pOut->PrintMessage("choose all of the black shapes");
	//	right_ans=arr[1];
		do{
		
		pIn->GetPointClicked(x,y);
		CFigure* SH=pManager->GetFigure(x,y);
		if(y>=0 &&y<UI.ToolBarHeight){
				arr[Shape_colored_Num]=0;
		 }
	//	pManager->setselected(SH);
		else if(SH->get_shape_color()==BLACK||SH->get_filled_color()==BLACK){		
				
				arr[1]--;
				pManager->setSelect(SH);
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
	
		while(arr[1]!=0);
	}
	////////////////////////////////////////////////////////////////////////////////
	if (Shape_colored_Num==2){
		pOut->PrintMessage("choose all of the red shapes");
	//	right_ans=arr[2];
		do{
		
		pIn->GetPointClicked(x,y);
		CFigure* SH=pManager->GetFigure(x,y);
		if(y>=0 &&y<UI.ToolBarHeight){
				arr[Shape_colored_Num]=0;
		 }
	//	pManager->setselected(SH);
		else if(SH->get_shape_color()==RED||SH->get_filled_color()==RED){		
				
				arr[2]--;
				pManager->setSelect(SH);
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
	
		while(arr[2]!=0);
	}
	///////////////////////////////////////////////////////////////////////////////////////////
	if (Shape_colored_Num==3){
		pOut->PrintMessage("choose all of the blue shapes");
		//right_ans=arr[3];
		do{
		
		pIn->GetPointClicked(x,y);
		CFigure* SH=pManager->GetFigure(x,y);
		if(y>=0 &&y<UI.ToolBarHeight){
				arr[Shape_colored_Num]=0;
		 }
	//	pManager->setselected(SH);
		else if(SH->get_shape_color()==BLUE||SH->get_filled_color()==BLUE){		
				
				arr[3]--;
				pManager->setSelect(SH);
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
	
		while(arr[3]!=0);
	}
	if (Shape_colored_Num==4){
		pOut->PrintMessage("choose all of the green shapes");
	//	right_ans=arr[4];
		do{
		
		pIn->GetPointClicked(x,y);
		CFigure* SH=pManager->GetFigure(x,y);
		if(y>=0 &&y<UI.ToolBarHeight){
				arr[Shape_colored_Num]=0;
		 }
	//	pManager->setselected(SH);
		else if(SH->get_shape_color()==GREEN||SH->get_filled_color()==GREEN){		
				
				arr[4]--;
				pManager->setSelect(SH);
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
	
		while(arr[4]!=0);
	}
	std::string ra = std::to_string(right_ans);
					std::string wa= std:: to_string(wrong_ans);

				pOut->PrintMessage("right answers:"+ra+"wrong answers: "+wa);
}


Pick_Color::~Pick_Color(void)
{
}
