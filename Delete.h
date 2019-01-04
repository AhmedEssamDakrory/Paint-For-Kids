#pragma once
#include "Actions\Action.h"
#include "GUI\UI_Info.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "Figures\CFigure.h"
#include "ApplicationManager.h"
#include <vector>
class Delete :
	public Action
{
	vector<CFigure*>SelectedFigure;
	Output* pOut ;
	Input* pIn;
public:
	Delete(ApplicationManager * );

	virtual void ReadActionParameters();
	
	//Execute action (code depends on action type)
	virtual void Execute();

	~Delete(void);
};

