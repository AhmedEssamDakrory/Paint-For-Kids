#pragma once
#include "Figures\CFigure.h"
#include "GUI\Output.h"
class CTriangle : public CFigure
{
	int ID;
private:
	Point Corner1;	
	Point Corner2;
	Point Corner3;
public:
	CTriangle(Point , Point, Point, GfxInfo FigureGfxInfo );
	virtual int GetID () const;
	virtual void increase ();
	virtual void decrease () ;
	virtual int GetNumber()const;
	virtual void Draw(Output* pOut) const;
	virtual bool OnFigure(Point)const;
	virtual void set_to_paste(Point p,Point d);
	virtual Point get_corner1();
	float sign (Point p1, Point p2, Point p3)const ;
	virtual void Save(ofstream &OutFile);
	virtual CFigure* GetCopy ();
	~CTriangle();
};