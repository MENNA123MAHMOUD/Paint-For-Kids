#include "CFigure.h"
#include "CRectangle.h"
#include "../ApplicationManager.h"
CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}
CFigure::CFigure()
{
	Selected = false;
}
void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }
color CFigure::getDRAWClr() {
	return FigGfxInfo.DrawClr;
}
void CFigure::printinfo(Output*p) {}
void CFigure::setid(int n) {
	ID = n;
}
int CFigure::getid() { return ID; }
void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}
color CFigure::getFillClr() {
	return FigGfxInfo.FillClr;
}
bool CFigure::getfigure(int x,int y){return 0;}
void CFigure::pstfig(int x, int y) {
}
GfxInfo CFigure::getgraphics() {
	return FigGfxInfo;
}
void CFigure::setgraphics(GfxInfo g) {
	FigGfxInfo = g;
}
 CFigure* CFigure::createfig(){
	 return this;
 }
 color CFigure::get_shape_color() {
	 return FigGfxInfo.DrawClr;
 }
 color CFigure::get_filled_color() {
	 return FigGfxInfo.FillClr;
 }