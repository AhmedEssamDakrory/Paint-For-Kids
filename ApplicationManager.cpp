#include "ApplicationManager.h"


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	int x,y;
	//Ask the input to get the action from the user.
	return pIn->GetUserAction(x,y);		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case SELEC:
			pAct = new Select(this);
			break;

		case DEL:
			pAct=new Delete(this);
			break;

		case CHNG_DRAW_CLR:
			if(SelectedFig.size()!=0)
			{
				pAct = new ChangeFigureColors(this,MODE_DRAW_COLOR);
			    break;
			}
			else
			{
				pOut->CreateColorToolBar(1);
	     		pAct=new ChangeCurrentColors(this);
	    		break;
			}

		case CHNG_FILL_CLR:
			if(SelectedFig.size()!=0)
			{
				pAct = new ChangeFigureColors(this,MODE_FILL_COLOR);
	     		break;
			}
			else
			{
				pOut->CreateColorToolBar(0);
	    		pAct=new ChangeCurrentColors(this);
	    		break;
			}

		case DRAW_LINE:
			pAct = new AddLineAction(this);
			///create AddLineAction here

			break;

		case DRAW_TRI:
			pAct = new AddTriangleAction(this); 

			break;

		case DRAW_CIRC:
			pAct = new AddCircleAction(this);

			break;

		case PASTE:
			pAct =new Paste_Figures(this);
			break;

		case COPY:
			pAct = new Copy_Figures(this);
			break;

		case CUT :
			pAct= new CutAction(this);
			break;

		case SAVE:
			pAct = new Save(this);
			break;
		case LOAD:
			pAct = new Load(this);
			break;
		case TO_PLAY:
			pAct = new PickAndHide(this);
			break;
		case EXIT:
			///create ExitAction here
			pAct = new Exit(this);
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}

void ApplicationManager::SaveAll(ofstream &OutFile) {
	for (int i = 0; i < FigCount; ++i) {
		FigList[i]->Save(OutFile);
	}
}

void ApplicationManager::Clean() {
	FigList.clear();
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	pFig->increase();
	if(FigCount < MaxFigCount )
		FigList.push_back(pFig);	
	FigCount=FigList.size();
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(Point P) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	CFigure* S=NULL;

	//Add your code here to search for a figure given a point x,y	
	for (int i=0;i<FigCount;i++)
		if (FigList[i]->OnFigure(P))
			S=FigList[i];
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return S;
}


//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pOut->ClearDrawArea();
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
/////////////////////////////////////////////////////

////////////////////////////////////////////
int ApplicationManager::GetCount()const
{
	return FigCount;
}
CFigure* ApplicationManager::GetCopyFromFigureLise(int i)const
{
	return FigList[i];
}
///////////////////////////////////////////////////////////////////////////////////
int ApplicationManager::GetNUmOfSelectedFig()const
{
	return SelectedFig.size();
}
/////////////////////////////////////////////
CFigure* ApplicationManager::GetSelectedFigure (int i)const
{
	return SelectedFig[i];
}
//////////////////////////////////////////////
void ApplicationManager::SetSelectedFigure(CFigure* Figure)
{
	SelectedFig.push_back(Figure);
}

void ApplicationManager::AddtoClipboard(CFigure* figure)
{
	Clipboard.push_back(figure->GetCopy());
}

void ApplicationManager::ClearClipboard()
{
	Clipboard.clear();
}

CFigure* ApplicationManager::GET_CP_Figure(int i) const
{
	return Clipboard[i];
}

int ApplicationManager:: get_num_ofCopiedFigures()
{
	return Clipboard.size();
}
/////////////////////////////////////////////////////////////
void ApplicationManager::CansSelectedFigure(CFigure* Figure)
{
		for(int i=0;i<SelectedFig.size();i++)
	{
		if (SelectedFig[i]==Figure)
		{
			SelectedFig.erase(SelectedFig.begin()+i);
			break;
		}
	}
}
//////////////////////////////////////////////////////////////
void ApplicationManager::DeleteSelectedFigure(CFigure* Figure)
{
	Figure->decrease();
	for(int i=0;i<FigCount;i++)
	{
		if (FigList[i]==Figure)
		{
			FigList.erase(FigList.begin()+i);
			break;
		}
	}
	FigCount=FigList.size();
}

void ApplicationManager::SelectAll()
{
	SelectedFig.clear();
	for (int i = 0; i < FigCount; i++)
		SelectedFig.push_back(FigList[i]);
}
