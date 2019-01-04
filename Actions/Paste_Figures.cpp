#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include "../ApplicationManager.h"
#include "../DEFS.h"

Paste_Figures ::Paste_Figures(ApplicationManager* app):Action(app)
{

}

void Paste_Figures::ReadActionParameters()
{
	Output* pOut =pManager->GetOutput();
	Input* pIn =pManager->GetInput();
	pOut->PrintMessage("click where you want to paste figures");
	pIn->GetPointClicked(p.x,p.y);
}

void Paste_Figures::Execute()
{
	if(pManager->get_num_ofCopiedFigures()==0)
		return;
	ReadActionParameters();
	Point d=pManager->GET_CP_Figure(0)->get_corner1();
	CFigure* Current;
	for(int i=0;i<pManager->get_num_ofCopiedFigures();i++)
	{
		Current = pManager->GET_CP_Figure(i)->GetCopy();
		Current->set_to_paste(p,d);
		Current->SetSelected(false);
		pManager->AddFigure(Current);
	} 
	
	for(int i=0;i<pManager->get_num_ofCopiedFigures();i++)
    {
		pManager->CansSelectedFigure(pManager->GET_CP_Figure(i));
	    	pManager->GET_CP_Figure(i)->SetSelected(false);
	}
}
