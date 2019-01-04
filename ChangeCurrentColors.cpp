#include "ChangeCurrentColors.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"

ChangeCurrentColors::ChangeCurrentColors(ApplicationManager* app):Action(app)
{
}

void ChangeCurrentColors::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if(UI.InterfaceMode==MODE_DRAW_COLOR)
	{
	pOut->PrintMessage("New color :change Draw color");
	do
	{
		int x,y;
		ActType2=pIn->GetUserAction(x,y);
    }while (ActType2==EMPTY || ActType2==DRAWING_AREA);

	if(ActType2!=BACK)
		{
			pOut->ChangeDrawColor(ActType2);
		}
	}
	else if(UI.InterfaceMode==MODE_FILL_COLOR)
	{
		
		pOut->PrintMessage("New color :change fill color");
		do
		{
			int x,y;
			ActType2=pIn->GetUserAction(x,y);
		}while(ActType2==EMPTY || ActType2==DRAWING_AREA);
		if(ActType2!=BACK)
		{
			pOut->ChangeFillColor(ActType2);
		}
	}
	pOut->ClearStatusBar();
	pOut->CreateDrawToolBar();
}

void ChangeCurrentColors::Execute()
{
	ReadActionParameters();
}