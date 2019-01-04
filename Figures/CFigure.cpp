#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

int CFigure::nl=0;
int CFigure::nc=0;
int CFigure::nt=0;
int CFigure::nr=0;

int CFigure::GetNumOfLines ()const
{
	return nl;
}
int CFigure::GetNumOfCircles ()const
{
	return nc;
}
int CFigure::GetNumOfRectangles ()const
{
	return nr;
}
int CFigure::GetNumOfTriangles ()const
{
	return nt;
}

color CFigure::GetCurrentColor ()const
{
	return FigGfxInfo.FillClr;
}
bool CFigure::IsFilled()const
{
	return FigGfxInfo.isFilled;
}
void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

CFigure::~CFigure()
	{}