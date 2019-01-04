#include "Load.h"
#include <fstream>


Load::Load(ApplicationManager * pApp) :Action(pApp) {
	pIn = pManager->GetInput();
	pOut = pManager->GetOutput();
}

void Load::ReadActionParameters() {
	pOut->PrintMessage("Enter name of save file to be loaded: ");
	filename = pIn->GetSrting(pOut);
	filename += ".txt";
}

void Load::Execute() {
	
	ReadActionParameters();
	if (filename == ".txt") {
		pOut->PrintMessage("Load Cancelled");
		return;
	}
	ifstream inputFile(filename);
	if (!inputFile.is_open()) {
		pOut->PrintMessage("File not found.");
		return;
	}
	pManager->Clean();
	int type,count;
	inputFile >> count;
	for (int i = 0; i < count; ++i) {
		inputFile >> type;
		switch (type)
		{
		case LINE: {
			AddLineAction LineAct(pManager);
			LineAct.Load(inputFile);
			break;
		}
		case RECTANGLE: {
			AddRectAction RectAct(pManager);
			RectAct.Load(inputFile);
			break;
		}
		case TRIANGLE: {
			AddTriangleAction TriAct(pManager);
			TriAct.Load(inputFile);
			break;
		}
		case CIRCLE: {
			AddCircleAction CircleAct(pManager);
			CircleAct.Load(inputFile);
			break;
		}
		default:
			break;
		}
	}
	inputFile.close();
	pOut->PrintMessage("Done Loading.");
}

Load::~Load()
{
}
