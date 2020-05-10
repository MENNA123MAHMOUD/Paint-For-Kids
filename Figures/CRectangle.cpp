#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
CRectangle::CRectangle()
{
	
}

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
int CRectangle::getpoint1_x() {
	return Corner1.x;
}
int CRectangle::getpoint2_x() {
	return Corner2.x;
}
int CRectangle::getpoint1_y() {
	return Corner1.y;
}
int CRectangle::getpoint2_y() {
	return Corner2.y;
}
bool CRectangle::getfigure(int x, int y) {

	float sum = 0;
	int x1 = this->getpoint1_x(); int x2 = this->getpoint2_x(); int y1 = this->getpoint1_y();  int y2 = this->getpoint2_y();
	float a1 = abs(x*y1 + x2 * y1 + x1 * y - x * y1 - x1 * y1 - x2 * y) / 2.0;
	float a2 = abs(x*y1 + x2 * y2 + x2 * y - x * y2 - x2 * y1 - x2 * y) / 2.0;
	float a3 = abs(x*y2 + x1 * y2 + x2 * y - x * y2 - x2 * y2 - x1 * y) / 2.0;
	float a4 = abs(x*y2 + x1 * y1 + x1 * y - x * y1 - x1 * y2 - x1 * y) / 2.0;
	sum = a1 + a2 + a3 + a4;
	float aR = abs(x1*y2 + x2 * y2 + x1 * y1 - x1 * y2 - x1 * y2 - x2 * y1) / 2.0 + abs(x1*y2 + x2 * y2 + x1 * y1 - x1 * y2 - x1 * y2 - x2 * y1) / 2.0;
	if (aR == sum) { return true; }

	else return false;
}
int CRectangle::getwidth() {
	int width = abs(Corner1.x - Corner2.x);
	return width;
}
int CRectangle::getlength() {
	int length = abs(Corner1.y - Corner2.y);
	return length;
}
void CRectangle::pstfig(int x, int y) {
	int l = getlength();
	int w = getwidth();
	Corner1.x = x - w/2.0;
	Corner2.x = x + w/2.0;
	Corner1.y = y - l/2.0;
	Corner2.y = y + l/2.0;
	if (Corner2.x >= 1250) {
		int transform = abs(Corner2.x - 1243);
		Corner1.x = Corner1.x - transform;
		Corner2.x = 1243;
	}
	if (Corner1.x <= 0) {
		int transform = abs(Corner1.x -3);
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
}
CFigure* CRectangle::createfig() {
	CRectangle* r = new CRectangle(Corner1, Corner2, FigGfxInfo);
	return r;
}
void CRectangle::printinfo(Output*pOut) {
	long long d = getid();
	long long width = Corner2.x - Corner1.x;
	long long height = Corner2.y - Corner1.y;
	string s1 = to_string(d);
	string s2 = to_string(width);
	string s3 = to_string(height);
	pOut->PrintMessage(" Rectangle id= " + s1 + "  width = " + s2 + "  height = " + s3);

}
void CRectangle::Save(ofstream & OutFile)
{
	color c = FigGfxInfo.DrawClr;
	color c1 = FigGfxInfo.FillClr;


	OutFile << "RECT" << "  " << ID << "  " << Corner1.x << "  " << Corner1.y;
	OutFile << "  " << Corner2.x << "  " << Corner2.y << "  ";
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
void CRectangle::Load(ifstream &Infile)
{

	string l1, l2;
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y;
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