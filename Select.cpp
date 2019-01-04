#include "Select.h"

Select::Select(ApplicationManager *pApp):Action(pApp)
{
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
}

void Select::ReadActionParameters()
{
	actType=pIn->GetUserAction(P.x, P.y);

	pOut->ClearStatusBar();

	for(int i=0;i<pManager->GetNUmOfSelectedFig();i++)
		SelectedFigures.push_back(pManager->GetSelectedFigure(i));
}
	
	//Execute action (code depends on action type)
void Select::Execute() 
{
	pOut->PrintMessage("Select any Figure, Click on Select Icon to Unselect all the selected figures");
	do
	{	
		ReadActionParameters();

    	CFigure* Figure =pManager->GetFigure(P);
    	if (Figure!=NULL)
    	{
    		if(Figure->IsSelected())
    		{
				for (int i = 0; i < SelectedFigures.size(); i++)
				{
					if (Figure==SelectedFigures[i])
					{
						pOut->PrintMessage2("You unselect the Figure :   ",Figure->GetID());
						SelectedFigures.erase(SelectedFigures.begin()+i);
						Figure->SetSelected(!(Figure->IsSelected()));
	             	    pManager->CansSelectedFigure(Figure); 
						break;
					}
				}
    		}
    		else
    		{
				pOut->PrintMessage2("You select the Figure :   ",Figure->GetID());
				SelectedFigures.push_back(Figure);
    			Figure->SetSelected(!(Figure->IsSelected()));
    		    pManager->SetSelectedFigure(Figure);
    		}
    	}
		pManager->UpdateInterface();
	}while(actType==DRAWING_AREA);

	if (actType==SELEC)
	{
		for(int i=0;i<SelectedFigures.size();i++)
		{
			SelectedFigures[i]->SetSelected(false);
			pManager->CansSelectedFigure(SelectedFigures[i]);
		}
	}

}


Select::~Select(void)
{
}
