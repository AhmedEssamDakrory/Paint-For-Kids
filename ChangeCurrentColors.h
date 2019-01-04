#pragma once
#include "Actions\Action.h"
#include "GUI\UI_Info.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "Figures\CFigure.h"
#include "ApplicationManager.h"



class ChangeCurrentColors:public Action{
	ActionType ActType2;
public:
	ChangeCurrentColors(ApplicationManager* app);
	virtual void ReadActionParameters();
	virtual void Execute() ;
};
