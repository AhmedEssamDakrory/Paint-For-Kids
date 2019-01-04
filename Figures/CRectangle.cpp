#include "CRectangle.h"
#include <iostream>
#include <fstream>
CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	ID=2000+nr;
}
	
int CRectangle:: GetNumber()const
{
	return nr;
}
void CRectangle::increase ()
{
	nr++;
}
void CRectangle:: decrease () 
{
	nr--;
}
void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

void CRectangle:: set_to_paste(Point p,Point d)
{
	Point p0;
	Point p1;
	p0.x=Corner1.x-d.x;
	p0.y=Corner1.y-d.y;
	p1.x=Corner2.x-d.x;
	p1.y=Corner2.y-d.y;
	Corner1.x=p.x+p0.x;
	Corner1.y=p.y+p0.y;
	Corner2.x=p.x+p1.x;
	Corner2.y=p.y+p1.y;
}

Point CRectangle :: get_corner1()
{
	return Corner1;
}

CRectangle& CRectangle:: get_rectangle()
{
	return *this;
}

CFigure* CRectangle::GetCopy ()
	{
	CFigure* Copy=new CRectangle(*this);
	return Copy;
	}


bool CRectangle::OnFigure(Point P)const
{
	if (P.x>=Corner1.x&&Corner2.x>=P.x&&P.y>=Corner1.y&&Corner2.y>=P.y)
		return true;
	if (P.x<=Corner1.x&&Corner2.x<=P.x&&P.y<=Corner1.y&&Corner2.y<=P.y)
		return true;
	if (P.x<=Corner1.x&&Corner2.x<=P.x&&P.y>=Corner1.y&&Corner2.y>=P.y)
		return true;
	if (P.x>=Corner1.x&&Corner2.x>=P.x&&P.y<=Corner1.y&&Corner2.y<=P.y)
		return true;
	return false;
}

int CRectangle::GetID () const
{
	return ID;
}
void CRectangle::Save(ofstream &OutFile) {
	if (OutFile.is_open()) {
		OutFile << "\n1" << "\t" << Corner1.x << " " << Corner1.y << "\t" << Corner2.x << " " << Corner2.y;
		OutFile << "\t" << FigGfxInfo.DrawClr.ucRed << " " << FigGfxInfo.DrawClr.ucGreen << " " << FigGfxInfo.DrawClr.ucBlue;
		OutFile << "\t" << FigGfxInfo.isFilled;
		if (FigGfxInfo.isFilled) {
			OutFile << "\t" << FigGfxInfo.FillClr.ucRed << " " << FigGfxInfo.FillClr.ucGreen << " " << FigGfxInfo.FillClr.ucBlue;
		}
	}
}

CRectangle::~CRectangle()
{
}