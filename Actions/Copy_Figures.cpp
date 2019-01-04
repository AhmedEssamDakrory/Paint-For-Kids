#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include "../ApplicationManager.h"

Copy_Figures::Copy_Figures(ApplicationManager* app) : Action(app)
	{	pOut = pManager->GetOutput();
	}

void Copy_Figures::ReadActionParameters()
	{	
	CopiedNum=pManager->GetNUmOfSelectedFig();
	for(int i=0;i<CopiedNum;i++)
		{
		CopiedFigures.push_back( pManager->GetSelectedFigure(i) );
		}
	pOut->PrintMessage("Selected Files Copied to the Clipboard.");
	}

void Copy_Figures::Execute()
{
	pManager->ClearClipboard();
	ReadActionParameters();
	for(int i=0;i<CopiedNum;i++)
		pManager->AddtoClipboard(CopiedFigures[i]);
	CopiedFigures.clear();
}

Copy_Figures::~Copy_Figures()
	{
	}