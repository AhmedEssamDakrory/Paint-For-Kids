#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include "../ApplicationManager.h"
#include "../Figures/CRectangle.h"
#include "CutAction.h"
 
CutAction::CutAction(ApplicationManager* app) : Action(app)
	{	pOut = pManager->GetOutput(); }

void CutAction::ReadActionParameters()
	{
	CutNum=pManager->GetNUmOfSelectedFig();
	for(int i=0;i<CutNum;i++)
		{
		CutFigures.push_back( pManager->GetSelectedFigure(i)->GetCopy() );
		pManager->DeleteSelectedFigure(pManager->GetSelectedFigure(i));
		}
	}

void CutAction::Execute()
	{
	pManager->ClearClipboard();
	ReadActionParameters();
	for(int i=0;i<CutNum;i++)
		pManager->AddtoClipboard(CutFigures[i]);
	pOut->PrintMessage("Selected Files Cut to the Clipboard.");
	}

CutAction::~CutAction()
	{}