#include "Cline.h"

Cline::Cline(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
Cline::Cline() 
{
	
}

void Cline::Draw(Output* pOut) const
{
	
	pOut->DrawLine(Corner1, Corner2, FigGfxInfo, Selected);
}
int Cline::getpoint1_x() {
	return Corner1.x;
}
int Cline::getpoint2_x() {
	return Corner2.x;
}
int Cline::getpoint1_y() {
	return Corner1.y;
}
int Cline::getpoint2_y() {
	return Corner2.y;
}
bool Cline::getfigure(int x, int y) {
	int d1 = sqrt(powf((x - Corner1.x), 2) + powf((y - Corner1.y), 2));
	int d2 = sqrt(powf((x - Corner2.x), 2) + powf((y - Corner2.y), 2));
	int dt = sqrt(powf((Corner2.x - Corner1.x), 2) + powf((Corner2.y - Corner1.y), 2));
	if ((d1 + d2) == dt) { return true; }
	else return false;
}
void Cline::printinfo(Output*pOut) {
	long long dd = getid();
	string s11 = to_string(dd);
	long long x111 = Corner1.x;
	string x11 = to_string(x111);
	long long x222 = Corner2.x;
	string x22 = to_string(x222);
	long long y111 = Corner1.y;
	string y11 = to_string(y111);
	long long y222 = Corner2.y;
	string y22 = to_string(y222);
	pOut->PrintMessage(" Line id= " + s11 + "  point 1= ( " + x11 + ", " + y11 + ")" + "  point 2=( " + x22 + " , " + y22 + ")");


}
int Cline::getmidx(){
	return (Corner1.x + Corner2.x) / 2;
}
int Cline::getmidy() {
	return (Corner1.y + Corner2.y) / 2;
}
void Cline::pstfig(int x, int y) {
	int transform_x = -getmidx() + x;
	int transform_y = -getmidy() + y;
	Corner1.x += transform_x;
	Corner1.y += transform_y;
	Corner2.x += transform_x;
	Corner2.y += transform_y;
	if (Corner2.x >= 1250) {
		int transform = abs(Corner2.x - 1243);
		Corner1.x = Corner1.x - transform;
		Corner2.x = 1243;
	}
	if (Corner1.x <= 0) {
		int transform = abs(Corner1.x - 3);
		Corner1.x = 3;
		Corner2.x = Corner2.x + transform;
	}
	if (Corner1.y <= 50) {
		int transform = abs(Corner1.y - 53);
		Corner1.y = 53;
		Corner2.y = Corner2.y + transform;
	}
	if (Corner2.y >= 600) {
		int transform = abs(Corner2.y - 603);
		Corner2.y = 597;
		Corner1.y = Corner1.y - transform;
	}
	if (Corner2.x >= 1250) {
		int transform = abs(Corner1.x - 1243);
		Corner2.x = Corner2.x - transform;
		Corner1.x = 1243;
	}
	if (Corner2.x <= 0) {
		int transform = abs(Corner2.x - 3);
		Corner2.x = 3;
		Corner1.x = Corner1.x + transform;
	}
	if (Corner2.y <= 50) {
		int transform = abs(Corner2.y - 53);
		Corner2.y = 53;
		Corner1.y = Corner1.y + transform;
	}
	if (Corner1.y >= 600) {
		int transform = abs(Corner1.y - 603);
		Corner1.y = 597;
		Corner2.y = Corner2.y - transform;
	}
}
CFigure* Cline::createfig() {
	Cline* l = new Cline(Corner1, Corner2, FigGfxInfo);
	return l;
}
void  Cline::Save(ofstream &OutFile)
{
	color c = FigGfxInfo.DrawClr;

	OutFile << "LINE" << "  " << ID << "  " << Corner1.x << "  " << Corner1.y;
	OutFile << "  " << Corner2.x << "  " << Corner2.y << "  ";
	if (c == RED)
		OutFile << "RED" << endl;
	else if (c == WHITE)
		OutFile << "WHITE" << endl;
	else if (c == GREEN)
		OutFile << "GREEN" << endl;
	else if (c == BLUE)
		OutFile << "BLUE" << endl;
	else if (c == BLACK)
		OutFile << "BLACK" << endl;
}
void Cline::Load(ifstream & Infile)
{
	string l1;
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y;
	Infile >> l1;
	if (l1 == "RED")
		FigGfxInfo.DrawClr = RED;
	else if (l1 == "WHITE")
		FigGfxInfo.DrawClr = WHITE;
	else if (l1 == "GREEN")
		FigGfxInfo.DrawClr = GREEN;
	else if (l1 == "BLUE")
		FigGfxInfo.DrawClr = BLUE;
	else if (l1 == "BLACK")
		FigGfxInfo.DrawClr = BLACK;

	FigGfxInfo.isFilled = false;

}