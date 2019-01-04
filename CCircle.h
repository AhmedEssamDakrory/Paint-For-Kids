#pragma once
#include "Figures\CFigure.h"
#include "GUI\Output.h"

class CCircle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CCircle(Point , Point, GfxInfo FigureGfxInfo );
	virtual int GetID () const;
	virtual void decrease () ;
	virtual void increase () ;
	virtual int GetNumber()const;
	virtual void Draw(Output* pOut) const;
	virtual bool OnFigure(Point)const;
	double distance (Point ,Point )const;
	virtual void set_to_paste(Point p,Point d);
	virtual Point get_corner1();
	virtual void Save(ofstream &OutFile);
	virtual CFigure* GetCopy ();
	~CCircle();
};

