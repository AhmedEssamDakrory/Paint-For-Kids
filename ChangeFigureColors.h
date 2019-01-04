#pragma once
#include "Actions\Action.h"
#include "GUI\UI_Info.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "Figures\CFigure.h"
#include "ApplicationManager.h"
#include <vector>

class ChangeFigureColors :public Action
{
	GUI_MODE MODE;
	vector<CFigure*>SelectedFigure;
	ActionType actType;
	Output* pOut ;
	Input* pIn;
public:
	ChangeFigureColors(ApplicationManager *,GUI_MODE);

	virtual void ReadActionParameters();
	
	//Execute action (code depends on action type)
	virtual void Execute();

	~ChangeFigureColors(void);
};

