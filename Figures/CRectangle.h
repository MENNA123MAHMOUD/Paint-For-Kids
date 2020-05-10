#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point, Point, GfxInfo FigureGfxInfo);
	CRectangle();
	virtual void Draw(Output* pOut) const;
	int getpoint1_x();
	int getpoint1_y();
	int getpoint2_y();
	int getpoint2_x();
	bool getfigure(int x, int y);
	int getwidth();
	int getlength();
	void pstfig(int x, int y);
	CFigure* createfig();
	void printinfo(Output*p);
	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &Infile);
};

#endif