#include "Action.h"

class Paste_Figures:public Action
	{
	Input* pIn;
	Output* pOut;
	Point p;
	ActionType ActType;

public:
	Paste_Figures(ApplicationManager* app);
	virtual void ReadActionParameters();
	virtual void Execute();
};