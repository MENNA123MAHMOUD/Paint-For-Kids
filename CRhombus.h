#pragma once
#include "Figures\CFigure.h"

class CRhombus : public CFigure
{
private:
	Point point1;
	Point point2;
	Point point3;
	Point point4;
public:
	CRhombus(Point, Point, Point, Point, GfxInfo FigureGfxInfo);
	CRhombus();
	virtual void Draw(Output* pOut) const;
	int getpoint1_x();
	int getpoint1_y();
	int getpoint2_y();
	int getpoint2_x();
	int getpoint3_y();
	int getpoint3_x();
	int getpoint4_y();
	int getpoint4_x();
	void printinfo(Output*p);
	bool getfigure(int x, int y);
	void pstfig(int x, int y);
	CFigure* createfig();
	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &Infile);
};