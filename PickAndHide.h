#pragma once
#include "Actions\Action.h"
#include <vector>
#include "Figures\CFigure.h"
#include "ApplicationManager.h"
#include "CLine.h"
#include "CCircle.h"
#include "CTriangle.h"
#include "Figures\CRectangle.h"


class PickByColor;

class PickAndHide :public Action
{

protected:
	vector<CFigure*>FigureList;
	Output* pOut;
	Input* pIn;
	int score,correct,uncorrect;
	ActionType actType;
	Point P;
	CFigure* selected;

public:
	PickAndHide(ApplicationManager *);
	CFigure* Random () const;
	void Message(int ,CFigure* )const;
	void UpdateInterface() const;
	void Delete(CFigure* fig);
	void Load ();
	int GetType (CFigure*)const;
	virtual void ReadActionParameters();
	bool SameColor(color,color)const;
	virtual void Execute();
	CFigure * GetFigure(Point P) const;
	bool CheckFigure(CFigure*,int)const;
	bool IfColorExisting(CFigure*)const;
	bool checkColor_Figure(int f,color c,CFigure* rand) const;

	~PickAndHide(void);
};

