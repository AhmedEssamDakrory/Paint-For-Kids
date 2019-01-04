#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include "Select.h"
#include "ChangeFigureColors.h"
#include "Delete.h"
#include "Actions\AddRectAction.h"
#include <vector>
#include "AddCircleAction.h"
#include "AddLineAction.h"
#include "AddTriangleAction.h"
#include "ChangeCurrentColors.h"
#include "DEFS.h"
#include "Actions\Copy_Figures.h"
#include "Actions\Paste_Figures.h"
#include "Save.h"
#include "Load.h"
#include "Actions\CutAction.h"
#include "PickAndHide.h"
#include "Exit.h"


//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	vector <CFigure*> FigList;	//List of all figures (Array of pointers)
	vector <CFigure*> SelectedFig; //Pointer to the selected figure
	vector <CFigure*> Clipboard;   //Pointer to the copied/cut figure

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

public:	
	ApplicationManager(); 
	~ApplicationManager();
	

	int GetCount()const;
	CFigure* GetCopyFromFigureLise(int)const;
	CFigure* GetSelectedFigure (int )const;
	CFigure* GET_CP_Figure(int ) const;//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	void SetSelectedFigure(CFigure*);
	void AddtoClipboard(CFigure*);//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	int get_num_ofCopiedFigures();
	void ClearClipboard();//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	void CansSelectedFigure(CFigure*);
	int GetNUmOfSelectedFig()const;
	void DeleteSelectedFigure(CFigure*);
	void SelectAll();
	void SaveAll(ofstream &OutFile);
	void Clean();
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure( Point ) const; //Search for a figure given a point inside the figure
		
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
	
};

#endif