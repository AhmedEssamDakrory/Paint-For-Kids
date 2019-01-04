#pragma once
#include "Actions\Action.h"
#include "ApplicationManager.h"
class Save:public Action
{
	string filename;
	Input* pIn;
	Output* pOut;
public:
	Save(ApplicationManager * pApp);
	virtual void Execute();
	virtual void ReadActionParameters();
	~Save();
};



