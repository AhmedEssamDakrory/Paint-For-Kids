#include "CTriangle.h"
#include"Figures\CFigure.h"
#include "GUI\Output.h"
#include <iostream>
#include <fstream>

CTriangle::CTriangle(Point P1, Point P2,Point P3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
	ID=3000+nt;
}
	
int CTriangle::GetID () const
{
	return ID;
}
void CTriangle::increase ()
{
	nt++;
}
void CTriangle:: decrease () 
{
	nt--;
}

bool CTriangle::OnFigure(Point P)const
{
	bool b1, b2, b3;

	b1 = sign(P, Corner1, Corner2) < 0.0f;
    b2 = sign(P, Corner2, Corner3) < 0.0f;
    b3 = sign(P, Corner3, Corner1) < 0.0f;

    return ((b1 == b2) && (b2 == b3));
}

float CTriangle::sign (Point p1, Point p2, Point p3)const
{
	 return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawTrian(Corner1, Corner2,Corner3, FigGfxInfo, Selected);
}

CFigure* CTriangle::GetCopy ()
	{
	CFigure* Copy=new CTriangle(*this);
	return Copy;
	}

int CTriangle:: GetNumber()const
{
	return nt;
}

void CTriangle :: set_to_paste(Point p,Point d)
{
    Point p0;
	Point p1;
	Point p2;
	p0.x=Corner1.x-d.x;
	p0.y=Corner1.y-d.y;
	p1.x=Corner2.x-d.x;
	p1.y=Corner2.y-d.y;
	p2.x=Corner3.x-d.x;
	p2.y=Corner3.y-d.y;
	Corner1.x=p.x+p0.x;
	Corner1.y=p.y+p0.y;
	Corner2.x=p.x+p1.x;
	Corner2.y=p.y+p1.y;
	Corner3.x=p.x+p2.x;
	Corner3.y=p.y+p2.y;
}

Point CTriangle :: get_corner1()
{
	return Corner1;
}

void CTriangle::Save(ofstream &OutFile) {
	if (OutFile.is_open()) {
		OutFile << "\n2" << "\t" << Corner1.x << " " << Corner1.y << "\t" << Corner2.x << " " << Corner2.y << "\t" << Corner3.x << " " << Corner3.y;
		OutFile << "\t" << FigGfxInfo.DrawClr.ucRed << " " << FigGfxInfo.DrawClr.ucGreen << " " << FigGfxInfo.DrawClr.ucBlue;
		OutFile << "\t" << FigGfxInfo.isFilled;
		if (FigGfxInfo.isFilled) {
			OutFile << "\t" << FigGfxInfo.FillClr.ucRed << " " << FigGfxInfo.FillClr.ucGreen << " " << FigGfxInfo.FillClr.ucBlue;
		}
	}
}
CTriangle ::~CTriangle()
{
}