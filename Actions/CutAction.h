#pragma once
#include "Action.h"
#include "../Figures/CFigure.h"
#include <vector>

class CutAction : public Action
	{
	Output* pOut;
	vector <CFigure*> CutFigures;
	int CutNum;

	public:
		CutAction(ApplicationManager* app);
		virtual void CutAction::ReadActionParameters();
		virtual void CutAction::Execute();
		~CutAction(void);
	};