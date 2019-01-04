#pragma once
#include "Actions\Action.h"
#include <fstream>
class AddCircleAction :public Action
{
	Point P1;
	Point P2;
	GfxInfo RectGfxInfo;
	public:
		AddCircleAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	virtual void Execute() ;

	void Load(ifstream& input);
};
