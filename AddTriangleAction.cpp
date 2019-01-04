#include "AddTriangleAction.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include "CTriangle.h"


AddTriangleAction::AddTriangleAction(ApplicationManager * pApp):Action(pApp)
{}

void AddTriangleAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first corner");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("New Triangle: Click at third corner");

	pIn->GetPointClicked(P3.x, P3.y);

	if(UI.filled_OR_not) //default is not filled
		RectGfxInfo.isFilled = true;
	else
		RectGfxInfo.isFilled = false;
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

void AddTriangleAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a rectangle with the parameters read from the user
	CTriangle *R=new CTriangle(P1, P2,P3, RectGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
}

void AddTriangleAction::Load(ifstream& input) {
	input >> P1.x >> P1.y >> P2.x >> P2.y >> P3.x >> P3.y;
	input >> RectGfxInfo.DrawClr.ucRed >> RectGfxInfo.DrawClr.ucGreen >> RectGfxInfo.DrawClr.ucBlue;
	input >> RectGfxInfo.isFilled;
	if (RectGfxInfo.isFilled) {
		input >> RectGfxInfo.FillClr.ucRed >> RectGfxInfo.FillClr.ucGreen >> RectGfxInfo.FillClr.ucBlue;
	}
	CTriangle *R = new CTriangle(P1, P2, P3, RectGfxInfo);
	pManager->AddFigure(R);
}