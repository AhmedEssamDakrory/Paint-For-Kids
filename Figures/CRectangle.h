#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual int GetID () const;
	virtual void increase ();
	virtual void decrease () ;
	virtual int GetNumber()const;
	virtual void Draw(Output* pOut) const;
	CRectangle& get_rectangle();
	virtual void set_to_paste(Point p,Point d);
	virtual Point get_corner1();
	virtual bool OnFigure(Point)const;
	virtual void Save(ofstream &OutFile);
	virtual CFigure* GetCopy ();
	~CRectangle();
};

#endif