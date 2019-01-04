#include "Action.h"
#include "../Figures/CFigure.h"
#include <vector>
class Copy_Figures:public Action
	{
	Output* pOut;
	vector <CFigure*> CopiedFigures;
	int CopiedNum;
public:
	Copy_Figures(ApplicationManager* app);
	virtual void ReadActionParameters();
	virtual void Execute();
	~Copy_Figures();
};