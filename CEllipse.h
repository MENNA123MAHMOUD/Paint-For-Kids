#pragma once
#include "Figures/CFigure.h"

class CEllipse : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Center;
public:
	CEllipse(Point, Point, Point, GfxInfo FigureGfxInfo);
	CEllipse();
	virtual void Draw(Output* pOut) const;
	int getpoint1_x();
	int getpoint1_y();
	int getpoint2_y();
	int getpoint2_x();
	bool getfigure(int x, int y);
	void pstfig(int ,int);
	CFigure* createfig();
	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &Infile);
	void printinfo(Output*p);
};