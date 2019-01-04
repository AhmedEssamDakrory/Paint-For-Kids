#include "CLine.h"
#include "Figures\CFigure.h"
#include "GUI\Output.h"
#include <cmath>
#include <iostream>
#include <fstream>

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	ID=1000+nl;
}
int CLine:: GetNumber()const
{
	return nl;
}
void CLine::increase ()
{
	nl++;
}
void CLine:: decrease () 
{
	nl--;
}

bool CLine::OnFigure(Point P)const
{
	if((distance(Corner1,P) + distance(P,Corner2))/distance(Corner1,Corner2)<=1.0001)  
		return true;
    return false;
}

color CLine :: GetCurrentColor ()const
{
	return FigGfxInfo.DrawClr;
}

double  CLine::distance (Point a,Point b )const
{
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawLine(Corner1, Corner2, FigGfxInfo, Selected);
}
int CLine::GetID () const
{
	return ID;
}

void CLine :: set_to_paste(Point p,Point d)
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
Point CLine :: get_corner1()
{
	return Corner1;
}

void CLine::Save(ofstream &OutFile) {
	if (OutFile.is_open()) {
		OutFile << "\n0" << "\t" << Corner1.x << " " << Corner1.y << "\t" << Corner2.x << " " << Corner2.y;
		OutFile << "\t" << FigGfxInfo.DrawClr.ucRed << " " << FigGfxInfo.DrawClr.ucGreen << " " << FigGfxInfo.DrawClr.ucBlue;
		OutFile << "\t" << FigGfxInfo.isFilled;
		if (FigGfxInfo.isFilled) {
			OutFile << "\t" << FigGfxInfo.FillClr.ucRed << " " << FigGfxInfo.FillClr.ucGreen << " " << FigGfxInfo.FillClr.ucBlue;
		}
	}
}

CFigure* CLine::GetCopy ()
	{
	CFigure* Copy=new CLine(*this);
	return Copy;
	}
CLine::~CLine()
{
}
