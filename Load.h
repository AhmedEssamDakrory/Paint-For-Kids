#pragma once
#include "Actions\Action.h"
#include "ApplicationManager.h"
class Load:public Action
{
	string filename;
	Input* pIn;
	Output* pOut;
public:
	Load(ApplicationManager * pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~Load();
};

enum figuretype {
	LINE,
	RECTANGLE,
	TRIANGLE,
	CIRCLE
};