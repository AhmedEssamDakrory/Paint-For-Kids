#pragma once
#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\Output.h"
class CLine : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CLine(Point , Point, GfxInfo Figur);
	virtual int GetID () const;
	virtual void increase ();
	virtual void decrease () ;
	virtual int GetNumber()const;
    double distance (Point ,Point )const;
	virtual void Draw(Output* pOut) const;
	virtual bool OnFigure(Point)const;
	virtual void set_to_paste(Point p,Point d);
	virtual Point get_corner1();
	virtual void Save(ofstream &OutFile);
	virtual CFigure* GetCopy ();
	virtual color GetCurrentColor ()const;
	~CLine();
};

