#pragma once
#include "Figures/CFigure.h"


class Cline : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
public:
	Cline(Point, Point, GfxInfo FigureGfxInfo);
	Cline();
	virtual void Draw(Output* pOut) const;
	int getpoint1_x();
	int getpoint1_y();
	int getpoint2_y();
	int getpoint2_x();
	bool getfigure(int x, int y);
	int getmidx();
	int getmidy();
	void pstfig(int x, int y);
	void printinfo(Output*);
	CFigure* createfig();
	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &Infile);
};