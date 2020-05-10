#include "CRhombus.h"

CRhombus::CRhombus(Point P1, Point P2, Point P3, Point P4, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	point1 = P1;
	point2 = P2;
	point3 = P3;
	point4 = P4;
}
CRhombus::CRhombus()
{
	
}

void CRhombus::Draw(Output* pOut) const
{
	//Call Output::Drawtriangle to draw a triangle on the screen	
	pOut->DrawPolygon(point1, point2, point3, point4, FigGfxInfo, Selected);
}
int CRhombus::getpoint1_x() {
	return point1.x;
}
int CRhombus::getpoint2_x() {
	return point2.x;
}
int CRhombus::getpoint1_y() {
	return point1.y;
}
int CRhombus::getpoint2_y() {
	return point2.y;
}
int CRhombus::getpoint3_x() {
	return point3.x;
}
int CRhombus::getpoint3_y() {
	return point3.y;
}
int CRhombus::getpoint4_x() {
	return point4.x;
}
int CRhombus::getpoint4_y() {
	return point4.y;
}
bool CRhombus::getfigure(int x, int y) {

	float sum = 0;
	int x1 = this->getpoint1_x(); int x2 = this->getpoint2_x(); int y1 = this->getpoint1_y();  int y2 = this->getpoint2_y();
	int x3 = this->getpoint3_x(); int y3 = this->getpoint3_y(); int x4 = this->getpoint4_x(); int y4 = this->getpoint4_y();
	float a1 = abs(x*(y1 - y2) + x1 * (y2 - y) + x2 * (y - y1)) / 2.0;
	float a2 = abs(x*(y2 - y3) + x2 * (y3 - y) + x3 * (y - y2)) / 2.0;
	float a3 = abs(x*(y1 - y4) + x1 * (y4 - y) + x4 * (y - y1)) / 2.0;
	float a4 = abs(x*(y3 - y4) + x3 * (y4 - y) + x4 * (y - y3)) / 2.0;
	sum = a1 + a2 + a3 + a4;
	float aRh = abs(x1*(y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0 + abs(x1*(y4 - y3) + x4 * (y3 - y1) + x3 * (y1 - y4)) / 2.0;
	if (aRh == sum) { return true; }

	else return false;
}
void CRhombus::pstfig(int x, int y) {
	if (y <= 220 ) {
			int transform = abs(220 - y) + 3;
			y += transform;
		}
	if (y >= 430) {
		int transform = abs(430 - y) + 3;
		y -= transform;
	}
	if (x <= 100) {
		int transform = abs(100 - x) + 3;
		x += transform;
	}
	if (x >= 1150) {
		int transform = abs(1150 - x) + 7;
		x -= transform;
	}
		point1.x = x;
		point1.y = y + 170;
		point2.x = x - 100;
		point2.y = y;
		point3.x = x;
		point3.y = y - 170;
		point4.x = x + 100;
		point4.y = y;
}
CFigure* CRhombus::createfig() {
	CRhombus* r = new CRhombus(point1, point2,point3,point4, FigGfxInfo);
	return r;
}
void CRhombus::Save(ofstream &OutFile)
{
	color c = FigGfxInfo.DrawClr;
	color c1 = FigGfxInfo.FillClr;

	OutFile << "RHOMBUS" << "  " << ID << "  " << point1.x << "  " << point1.y << "  " << point2.x << "  " << point2.y << "  ";
	OutFile << point3.x << "  " << point3.y << "  " << point4.x << "  " << point4.y << "  ";
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
	{
		OutFile << "NO_FILL" << endl;
	}


}
void CRhombus::Load(ifstream & Infile)
{
	string l1, l2;
	Infile >> ID >> point1.x >> point1.y >> point2.x >> point2.y >> point3.x >> point3.y >> point4.x >> point4.y;
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
void CRhombus::printinfo(Output*pOut) {
	long long d = getid();
	string s1 = to_string(d);

	pOut->PrintMessage(" RHombus id= " + s1 + "  width = 200 height = 340");

}