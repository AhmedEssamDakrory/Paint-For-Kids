#include "Save.h"
#include <fstream>

Save::Save(ApplicationManager * pApp):Action(pApp){
	pIn = pManager->GetInput();
	pOut = pManager->GetOutput();
}

void Save::ReadActionParameters() {
	pOut->PrintMessage("Enter Save File name: ");
	filename = pIn->GetSrting(pOut);
	filename += ".txt";
}

void Save::Execute() {
	ReadActionParameters();
	if (filename == ".txt") {
		pOut->PrintMessage("Save Cancelled");
		return;
	}
	ofstream outputFile(filename);
	outputFile << pManager->GetCount();
	pManager->SaveAll(outputFile);
	outputFile.close();
	pOut->PrintMessage("Done saving.");
}

Save::~Save()
{
}
