#include "CEllipse.h"

CEllipse::CEllipse(Point P1, Point P2, Point P0, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Center = P0;
}
CEllipse::CEllipse()
{
	
}

void CEllipse::Draw(Output* pOut) const
{
	//Call Output::Drawtriangle to draw a triangle on the screen	
	pOut->DrawEllipse(Corner1, Corner2, FigGfxInfo, Selected);
}
int CEllipse::getpoint1_x() {
	return Corner1.x;
}
int CEllipse::getpoint2_x() {
	return Corner2.x;
}
int CEllipse::getpoint1_y() {
	return Corner1.y;
}
int CEllipse::getpoint2_y() {
	return Corner2.y;
}

bool CEllipse::getfigure(int x, int y) {

	float d1 = sqrt(powf((x - Center.x), 2) + powf((y - Center.y), 2));
	float d2 = sqrt(powf((x - Center.x), 2) + powf((y - Center.y - 140), 2));
	float d3 = sqrt(powf((x - Center.x + 190), 2) + powf((y - Center.y), 2));
	float d4 = sqrt(powf((x - Center.x - 190), 2) + powf((y - Center.y), 2));
	float d5 = sqrt(powf((x - Center.x), 2) + powf((y - Center.y + 140), 2));
	if ((d1 <= d3 || (d1 >= d2 && d1 <= d3)) && ((d1 <= d4) || (d1 >= d5 && d1 <= d4)) && ((d1 <= d2 && d1 <= d5) || ((d1 >= d2 && d1 <= d3) && (d1 >= d5 && d1 <= d4)))) return true;
	else return false;

}
void CEllipse::pstfig(int x,int y) {
	if (y <= 120 ) {
		int transform = abs(120 - y)+3;
		y += transform;
	}
	if (y >= 530) {
		int transform = abs(530 - y) +3;
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
	Corner1.x = x + 100;
	Corner1.y = y + 70;
	Corner2.x = x - 100;
	Corner2.y = y - 70;
	Center.x=x;
	Center.y=y;
}
CFigure* CEllipse::createfig() {
	CEllipse* E = new CEllipse (Corner1, Corner2, Center, FigGfxInfo);
	return E;
}
void CEllipse::Save(ofstream &OutFile)
{
	color c = FigGfxInfo.DrawClr;
	color c1 = FigGfxInfo.FillClr;

	OutFile << "ELLIPSE" << "  " << ID << "  " << Corner1.x << "  " << Corner1.y << "  " << Corner2.x << "  " << Corner2.y << "  ";
	OutFile << Center.x << "  " << Center.y << "  ";
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

void CEllipse::Load(ifstream &Infile)
{
	string l1, l2;
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Center.x >> Center.y;
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
void CEllipse::printinfo(Output*pOut) {
	long long a = getid();
	string l = to_string(a);
	long long c = Center.x;
	long long z = Center.y;
	string x = to_string(c);
	string y = to_string(z);
	pOut->PrintMessage(" Ellipse id= " + l + "  width=380  height=280  the center ( " + x + " , " + y + " )");


}