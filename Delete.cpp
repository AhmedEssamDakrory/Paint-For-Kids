#include "Delete.h"


Delete::Delete(ApplicationManager * pApp):Action(pApp)
{
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
}


void Delete::ReadActionParameters()
{
	for(int i=0;i<pManager->GetNUmOfSelectedFig();i++)
		SelectedFigure.push_back(pManager->GetSelectedFigure(i));

}
	
	//Execute action (code depends on action type)
void Delete::Execute()
{
	ReadActionParameters();
	int n=pManager->GetNUmOfSelectedFig();
	for(int i=0;i<n;i++)
	{
		pManager->CansSelectedFigure(SelectedFigure[0]);
		pManager->DeleteSelectedFigure(SelectedFigure[0]);
		delete SelectedFigure[0];
		SelectedFigure.erase(SelectedFigure.begin());
		//SelectedFigure.erase(SelectedFigure.begin());
	}
}

Delete::~Delete(void)
{
}
