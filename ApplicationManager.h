#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include<fstream>
#include "GUI\input.h"
#include "GUI\output.h"


//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	bool sound;
	int FigCount;		//Actual number of figures
	int FigCountCopy;
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure* CopyFigList[MaxFigCount];
	CFigure* SelectedFig; //Pointer to the selected figure
	CFigure* Clipboard;   //Pointer to the copied/cut figure
	GfxInfo gfx;
	bool b;
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

public:	
	ApplicationManager(); 
	~ApplicationManager();
	void deletefig();
	bool colortest;
	bool getcolored();
	void setcolored(bool);
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) ; //Search for a figure given a point inside the figure
		
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window
	void setclipboard(CFigure*);  
	CFigure* getclipboard();
	void setSelect(CFigure*);
	CFigure* getSelect();
	int getfigcount();
	void SaveAll(ofstream & out);
	void savebytype(ofstream & out, ActionType);
	void unselect();
	void overwritten();
	void setb(bool);
	bool getb();
	void deletegray();
	void setgfx(GfxInfo);
	GfxInfo getgfx();
	void get_number_of_shapes(int*);
	void copy_figs();
	void recopy_figlist();
	void get_number_of_colored_shapes(int*);
	bool get_sound();
	
};

#endif