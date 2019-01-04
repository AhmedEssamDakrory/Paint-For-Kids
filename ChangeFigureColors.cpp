#include "ChangeFigureColors.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
ChangeFigureColors::ChangeFigureColors(ApplicationManager *pApp,GUI_MODE mode):Action(pApp),MODE(mode)
{
	UI.InterfaceMode=MODE;
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
	pOut->CreateColorToolBar();
}

void ChangeFigureColors::ReadActionParameters()
{
	int x,y;

	for(int i=0;i<pManager->GetNUmOfSelectedFig();i++)
		SelectedFigure.push_back(pManager->GetSelectedFigure(i));
	
	pOut->PrintMessage("Select any Color");

	actType=pIn->GetUserAction(x, y);

	pOut->ClearStatusBar();
}

void ChangeFigureColors::Execute()
{
	do
	{
		ReadActionParameters();
	}while(actType>4);
	color color;

	switch ( actType )
	{
	case SET_BLACK: 
		color=BLACK;
		break;

	case SET_WHITE: 
		color=WHITE;
		break;

	case SET_RED: 
		color=RED;
		break;

	case SET_GREEN:
		color=GREEN;
		break;

	case SET_BLUE: 
		color=BLUE;
		break;

	}
	if (UI.InterfaceMode==MODE_DRAW_COLOR&&actType!=BACK)
		for(int i=0;i<SelectedFigure.size();i++)
			SelectedFigure[i]->ChngDrawClr(color);

	else if (actType!=BACK&&UI.InterfaceMode==MODE_FILL_COLOR)
		for(int i=0;i<SelectedFigure.size();i++)
			SelectedFigure[i]->ChngFillClr(color);

	if (actType!=BACK)
	{
		for(int i=0;i<SelectedFigure.size();i++)
    	{
	    	pManager->CansSelectedFigure(SelectedFigure[i]);
	    	SelectedFigure[i]->SetSelected(!(SelectedFigure[i]->IsSelected()));
    	}
	}
	
	pOut->CreateDrawToolBar();

}
ChangeFigureColors::~ChangeFigureColors(void)
{}
