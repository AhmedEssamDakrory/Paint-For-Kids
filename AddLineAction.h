#pragma once
#include "Actions\Action.h"
class AddLineAction :public Action{
	Point P1;
	Point P2;
	GfxInfo RectGfxInfo;
	public:
		AddLineAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	void Load(ifstream& input);

	//Add rectangle to the ApplicationManager
	virtual void Execute() ;
};