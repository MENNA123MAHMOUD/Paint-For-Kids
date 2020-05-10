#pragma once
#include "Figures\CFigure.h"

class Ctriangle : public CFigure
{
private:
	Point point1;
	Point point2;
	Point point3;
public:
	Ctriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	Ctriangle();
	virtual void Draw(Output* pOut) const;
	int getpoint1_x();
	int getpoint1_y();
	int getpoint2_y();
	int getpoint2_x();
	int getpoint3_y();
	int getpoint3_x();
	bool getfigure(int x, int y);
	void pstfig(int x, int y);
	CFigure* createfig();
	double getmidx();
	double getmidy();
	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &Infile);
	void printinfo(Output*p);
};
