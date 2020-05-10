#include "Ctriangle.h"

Ctriangle::Ctriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	point1 = P1;
	point2 = P2;
	point3 = P3;
}

Ctriangle::Ctriangle() 
{
	
}
void Ctriangle::Draw(Output* pOut) const
{
	//Call Output::Drawtriangle to draw a triangle on the screen	
	pOut->DrawTriangle(point1, point2, point3, FigGfxInfo, Selected);
}
int Ctriangle::getpoint1_x() {
	return point1.x;
}
int Ctriangle::getpoint2_x() {
	return point2.x;
}
int Ctriangle::getpoint1_y() {
	return point1.y;
}
int Ctriangle::getpoint2_y() {
	return point2.y;
}
int Ctriangle::getpoint3_x() {
	return point3.x;
}
int Ctriangle::getpoint3_y() {
	return point3.y;
}
bool Ctriangle::getfigure(int x, int y) {

	float sum = 0;
	int x1 = this->getpoint1_x(); int x2 = this->getpoint2_x(); int y1 = this->getpoint1_y();  int y2 = this->getpoint2_y();
	int x3 = this->getpoint3_x(); int y3 = this->getpoint3_y();
	float a1 = abs(x*(y1 - y2) + x1 * (y2 - y) + x2 * (y - y1)) / 2.0;
	float a2 = abs(x*(y2 - y3) + x2 * (y3 - y) + x3 * (y - y2)) / 2.0;
	float a3 = abs(x*(y1 - y3) + x1 * (y3 - y) + x3 * (y - y1)) / 2.0;
	sum = a1 + a2 + a3;
	float aT = abs(x1*(y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;
	if (aT == sum) { return true; }

	else return false;
}

double Ctriangle::getmidx() {
	return (1.0*point1.x + point2.x +point3.x) / (3);
}
double Ctriangle::getmidy() {
	return (1.0*point1.y + point2.y + point3.y) / (3);
}
void Ctriangle::pstfig(int x, int y) {
	int transform_x = -getmidx() + x;
	int transform_y = -getmidy() + y;
    point1.x += transform_x;
	point1.y +=  transform_y;
	point2.x +=  transform_x;
	point2.y +=  transform_y;
	point3.x +=  transform_x;
	point3.y +=  transform_y;
	if (point1.x >= 1250) {
		int delta = abs(point1.x - 1243);
		point1.x = point1.x - delta;
		point2.x = point2.x - delta;
		point3.x = point3.x - delta;
	}
	if (point2.x >= 1250) {
		int delta = abs(point2.x - 1243);
		point1.x = point1.x - delta;
		point2.x = point2.x - delta;
		point3.x = point3.x - delta;
	}
	if (point3.x >= 1250) {
		int delta = abs(point3.x - 1243);
		point1.x = point1.x - delta;
		point2.x = point2.x - delta;
		point3.x = point3.x - delta;
	}
	if (point1.x <= 0) {
		int delta = abs(point1.x - 3);
		point1.x = point1.x +delta;
		point2.x = point2.x + delta;
		point3.x = point3.x + delta;
	}
	if (point2.x <= 0) {
		int delta = abs(point2.x - 3);
		point1.x = point1.x + delta;
		point2.x = point2.x + delta;
		point3.x = point3.x + delta;
	}
	if (point3.x <= 0) {
		int delta = abs(point3.x - 3);
		point1.x = point1.x + delta;
		point2.x = point2.x + delta;
		point3.x = point3.x + delta;
	}
	if (point1.y <= 50) {
		int delta = abs(point1.y - 53);
		point1.y = point1.y +delta;
		point2.y = point2.y + delta;
		point3.y = point3.y + delta;
	}
	if (point2.y <= 50) {
		int delta = abs(point2.y - 53);
		point1.y = point1.y + delta;
		point2.y = point2.y + delta;
		point3.y = point3.y + delta;
	}
	if (point3.y <= 50) {
		int delta = abs(point3.y - 53);
		point1.y = point1.y + delta;
		point2.y = point2.y + delta;
		point3.y = point3.y + delta;
	}
	if (point1.y >= 600) {
		int delta = abs(point1.y - 597);
		point1.y = point1.y -delta;
		point2.y = point2.y - delta;
		point3.y = point3.y - delta;
	}
	if (point2.y >= 600) {
		int delta = abs(point2.y - 597);
		point1.y = point1.y - delta;
		point2.y = point2.y - delta;
		point3.y = point3.y - delta;
	}
	if (point3.y >= 600) {
		int delta = abs(point3.y - 597);
		point1.y = point1.y - delta;
		point2.y = point2.y - delta;
		point3.y = point3.y - delta;
	}
}
CFigure* Ctriangle::createfig() {
	Ctriangle* t = new Ctriangle(point1, point2,point3, FigGfxInfo);
	return t;
}
void Ctriangle::Save(ofstream &OutFile)
{
	color c = FigGfxInfo.DrawClr;
	color c1 = FigGfxInfo.FillClr;
	OutFile << "TRING" << "  " << ID << "  " << point1.x << "  " << point1.y;
	OutFile << "  " << point2.x << "  " << point2.y << "  " << point3.x << "  " << point3.y << "  ";
	if (c == RED)
		OutFile << "RED" << "  ";
	else if (c == WHITE)
		OutFile << "WHITE" << "  ";
	else if (c == GREEN)
		OutFile << "GREEN" << "  ";
	else if (c == BLUE)
		OutFile << "BLUE" << "  ";
	else if (c == BLACK)
		OutFile << "BLACK" << "  ";

	if (FigGfxInfo.isFilled)
	{
		if (c1 == RED)
			OutFile << "RED" << endl;
		else if (c1 == WHITE)
			OutFile << "WHITE" << endl;
		else if (c1 == GREEN)
			OutFile << "GREEN" << endl;
		else if (c1 == BLUE)
			OutFile << "BLUE" << endl;
		else if (c1 == BLACK)
			OutFile << "BLACK" << endl;
		else
			OutFile << "NO_FILL" << endl;
	}
	else
		OutFile << "NO_FILL" << endl;
}
void Ctriangle::Load(ifstream &Infile)
{
	string l1, l2;
	Infile >> ID >> point1.x >> point1.y >> point2.x >> point2.y >> point3.x >> point3.y;
	Infile >> l1 >> l2;
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


	if (l2 == "NO_FILL")
		FigGfxInfo.isFilled = false;
	else if (l2 == "RED")
		FigGfxInfo.FillClr = RED;
	else if (l2 == "WHITE")
		FigGfxInfo.FillClr = WHITE;
	else if (l2 == "GREEN")
		FigGfxInfo.FillClr = GREEN;
	else if (l2 == "BLUE")
		FigGfxInfo.FillClr = BLUE;
	else if (l2 == "BLACK")
		FigGfxInfo.FillClr = BLACK;



}
void Ctriangle::printinfo(Output*pOut) {
	long long d = getid();
	string s1 = to_string(d);
	long long x1 = point1.x;
	string x11 = to_string(x1);
	long long x2 = point2.x;
	string x22 = to_string(x2);
	long long x3 = point3.x;
	string x33 = to_string(x3);
	long long y1 = point1.y;
	string y11 = to_string(y1);
	long long y2 = point2.y;
	string y22 = to_string(y2);
	long long y3 = point3.y;
	string y33 = to_string(y3);
	pOut->PrintMessage(" Triangle id= " + s1 + "  point 1= ( " + x11 + ", " + y11 + ")" + "  point 2=( " + x22 + " , " + y22 + ")" + "  point 3=( " + x33 + " , " + y33 + ")");



}