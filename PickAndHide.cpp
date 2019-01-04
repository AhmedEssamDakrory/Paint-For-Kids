#include "PickAndHide.h"


PickAndHide::PickAndHide(ApplicationManager * pApp):Action(pApp)
{
	score=correct=uncorrect=0;
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
	pOut->CreatePlayToolBar();
}

void PickAndHide::ReadActionParameters()
{

	for(int i =0 ; i < pManager->GetCount() ; i++)
		FigureList.push_back(pManager->GetCopyFromFigureLise(i)->GetCopy());//////////////////
}

void PickAndHide::UpdateInterface() const
{	
	pOut->ClearDrawArea();
	for(int i=0; i<FigureList.size(); i++)
		FigureList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
void PickAndHide::Load()
{
	FigureList.clear();

	ReadActionParameters();

	UpdateInterface();
}
CFigure * PickAndHide::GetFigure(Point P) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	CFigure* S=NULL;

	//Add your code here to search for a figure given a point x,y	
	for (int i=0;i<FigureList.size();i++)
		if (FigureList[i]->OnFigure(P))
			S=FigureList[i];
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return S;
}
int PickAndHide::GetType (CFigure* fig)const
{
	if(dynamic_cast<CLine*>(fig))
		return 1;

	if(dynamic_cast<CRectangle*>(fig))
		return 2;

	if(dynamic_cast<CTriangle*>(fig))
		return 3;

	if(dynamic_cast<CCircle*>(fig))
		return 4;
}

bool PickAndHide::checkColor_Figure(int f,color c,CFigure* rand) const
{

	for(int i=0;i<FigureList.size();i++)
	{
		
		if(dynamic_cast<CLine*>(FigureList[i]))
		{
			if(f==1)
			{
				if(FigureList[i]->IsFilled()&&rand->IsFilled())
				{
			     if(SameColor(FigureList[i]->GetCurrentColor(),c))
				 return true;
				}
			}
		}
		else if(dynamic_cast<CRectangle*>(FigureList[i]))
		{
			if(f==2)
			{
			if(FigureList[i]->IsFilled()&&rand->IsFilled())
				{
			     if(SameColor(FigureList[i]->GetCurrentColor(),c))
				 return true;
				}
		   }
		}
		else if(dynamic_cast<CTriangle*>(FigureList[i]))
		{
			if(f==3)
			{
			if(FigureList[i]->IsFilled()&&rand->IsFilled())
				{
			     if(SameColor(FigureList[i]->GetCurrentColor(),c))
				 return true;
				}
			}
		}
		else if(dynamic_cast<CCircle*>(FigureList[i]))
		{
			if(f==4)
			{
			if(FigureList[i]->IsFilled()&&rand->IsFilled())
				{
			     if(SameColor(FigureList[i]->GetCurrentColor(),c))
				 return true;
				}
			}
		}
}
	return false;
}

bool PickAndHide::CheckFigure(CFigure* fig,int m)const//1.line/2.rectangle/3.triangle/4.circle
{
	if (m==1)
	{
		if(dynamic_cast<CLine*>(fig))
			return true;
	}
	else if (m==2)
	{
		if(dynamic_cast<CRectangle*>(fig))
			return true;
	}
	else if (m==3)
	{
		if(dynamic_cast<CTriangle*>(fig))
			return true;
	}
	else if (m==4)
	{
		if(dynamic_cast<CCircle*>(fig))
			return true;
	}
	return false;
}
bool PickAndHide::IfColorExisting(CFigure* f)const
{
	for (int i=0;i<FigureList.size();i++)
		if (FigureList[i]->IsFilled()&&f->IsFilled())
		{
			if(SameColor(FigureList[i]->GetCurrentColor(),f->GetCurrentColor()))
				return true;
		}
		else if (!FigureList[i]->IsFilled()&&!f->IsFilled())
			return true;
	return false;
}

CFigure* PickAndHide::Random () const
{
	return FigureList[FigureList.size()/2];
}
void PickAndHide::Message(int mode,CFigure* figure)const//mode 1.by color/2.by Figure/3.by fig&col
{
	string Mode;
	string Figure;
	string Color;

	int type = GetType(figure);
	switch (type)
	{
	  case 1:
		Figure="Line ";
		break;
	  case 2:
		Figure="Rectangle ";
		break;
	  case 3:
		Figure="Triangle ";
		break;
	  case 4:
		Figure="Circle ";
		break;
	}


	if (!figure->IsFilled()&&!dynamic_cast<CLine*>(figure))
		Color="Non-Filled ";
	else if(SameColor(figure->GetCurrentColor(),WHITE))
		Color="White ";
	else if(SameColor(figure->GetCurrentColor(),RED))
		Color="Red ";
	else if(SameColor(figure->GetCurrentColor(),GREEN))
		Color="Green ";
	else if(SameColor(figure->GetCurrentColor(),BLACK))
		Color="Black ";
	else if(SameColor(figure->GetCurrentColor(),BLUE))
		Color="Blue ";


	if(mode==2)
	{
		Mode="Pick by figure, ";
		pOut->PrintMessage(Mode+Figure);
		return ;
	}
	else if (mode==1)
	{
		Mode="Pick by color, ";
		pOut->PrintMessage(Mode+Color);
		return ;
	}
	else if(mode ==3)
	{
		Mode="Pick by Figure & color ";
		pOut->PrintMessage(Mode+Figure+Color);
	}
}
bool PickAndHide::SameColor(color c1,color c2)const
{
	if (c1.ucBlue==c2.ucBlue&&c1.ucGreen==c2.ucGreen&&c1.ucRed==c2.ucRed)
		return true;
	return false;
}
void PickAndHide::Delete(CFigure* fig)
{
	for (int i=0;i<FigureList.size();i++)
		if(FigureList[i]==fig)
		{
			FigureList.erase(FigureList.begin()+i);
			UpdateInterface();
			break;
		}
}
void PickAndHide::Execute()
{	
	ReadActionParameters();
	bool Switch=false;
	do
	{
		Load();
		pOut->ClearStatusBar();
		if (!Switch)
			actType=pIn->GetUserAction(P.x, P.y);
		Switch=false;
		switch (actType)
		{
		case PC:
			{
				int Lifes=3;
				score=correct=uncorrect=0;
				do
				{
					CFigure* fig=Random();
					Message(1,fig);
					do 
					{
						selected=NULL;

						actType=pIn->GetUserAction(P.x, P.y);

						if(P.y >= 0 && P.y < UI.ToolBarHeight && P.x<=UI.MenuItemWidth*PLAY_ITM_COUNT)
						{
							Switch=true;
							break;
						}
						selected=GetFigure(P);
						if(selected!=NULL&&SameColor(fig->GetCurrentColor(),selected->GetCurrentColor())&&fig->IsFilled()&&selected->IsFilled())
						{
							score++;
							correct++;
							Delete(selected);
							pOut->PrintMessage2("Right selection well done, Your score :   ",score);
						}
						else if(selected!=NULL&&!fig->IsFilled()&&!selected->IsFilled())
						{
							score++;
							correct++;
							Delete(selected);
							pOut->PrintMessage2("Right selection well done, Your score :   ",score);
						}
						else if (selected!=NULL)
						{
							Lifes--;
							uncorrect++;
							if(score!=0)
							score--;
							pOut->PrintMessage2("Wrong selection Be careful, Your score :   ",score);
						}
					
					}while(IfColorExisting(fig)&&Lifes!=0);
				
				}while(FigureList.size()!=0&&Lifes!=0&&!Switch);
				
				if(Lifes!=0&&!Switch)
				{
					pOut->PrintMessage("You Win, Click to see the results");
					pIn->GetPointClicked(P.x,P.y);
				}
				else if(!Switch)
				{
					pOut->PrintMessage("You lose, Click to see the results");
					pIn->GetPointClicked(P.x,P.y);
				}
				if(!Switch)
				{
					pOut->PrintMessage2("your final score is  :  ",score);
			    	pIn->GetPointClicked(P.x,P.y);
					pOut->PrintMessage2("Your correct selection :  ",correct);
					pIn->GetPointClicked(P.x,P.y);
					pOut->PrintMessage2("Your uncorrect selection :  ",uncorrect);
					pIn->GetPointClicked(P.x,P.y);
					pOut->ClearStatusBar();
				}
				break;
			}
		case PF:
			{
				int Lifes=3;
				score=correct=uncorrect=0;
				do
				{
					CFigure* fig=Random();
					int n = fig->GetNumber();
					Message(2,fig);
					do 
					{
						actType=pIn->GetUserAction(P.x, P.y);
						if(P.y >= 0 && P.y < UI.ToolBarHeight && P.x<=UI.MenuItemWidth*PLAY_ITM_COUNT)
						{
							Switch=true;
							break;
						}
						selected=NULL;
						selected=GetFigure(P);
						if(selected!=NULL&&CheckFigure(selected,GetType(fig)))
						{
							n--;
							score++;
							correct++;
							Delete(selected);
							pOut->PrintMessage2("Right selection well done, Your score :   ",score);
						}
						else if (selected!=NULL)
						{
							Lifes--;
							uncorrect++;
							if(score!=0)
							score--;
							pOut->PrintMessage2("Wrong selection Be careful, Your score :   ",score);
						}
					
					}while(n!=0&&Lifes!=0);
				
				}while(FigureList.size()!=0&&Lifes!=0&&!Switch);
				
				if(Lifes!=0&&!Switch)
				{
					pOut->PrintMessage("You Win, Click to see the results");
					pIn->GetPointClicked(P.x,P.y);
				}
				else if(!Switch)
				{
					pOut->PrintMessage("You lose, Click to see the results");
					pIn->GetPointClicked(P.x,P.y);
				}
				if(!Switch)
				{
					pOut->PrintMessage2("your final score is  :  ",score);
			    	pIn->GetPointClicked(P.x,P.y);
					pOut->PrintMessage2("Your correct selection :  ",correct);
					pIn->GetPointClicked(P.x,P.y);
					pOut->PrintMessage2("Your uncorrect selection :  ",uncorrect);
					pIn->GetPointClicked(P.x,P.y);
					pOut->ClearStatusBar();
				}
				break;
			}
		case PFI:
			{
				Load();
				int lifes=3;
				score=correct=uncorrect=0;
				CFigure* rand=Random();
				int number_of_exited=rand->GetNumber();
				Message(3,rand);
				do{

					actType=pIn->GetUserAction(P.x,P.y);
					CFigure* sel =GetFigure(P);
					if(sel!=NULL)
					{
					do
					{
					while(sel==NULL){actType=pIn->GetUserAction(P.x,P.y); sel =GetFigure(P);}
					if(CheckFigure(sel,GetType(rand)))
					{
						
						
							if(SameColor(sel->GetCurrentColor(),rand->GetCurrentColor())&&sel->IsFilled()&&rand->IsFilled())
						    {
							   score++;
							   correct++;
							   Delete(sel);
							   number_of_exited--;
							   pOut->PrintMessage2("right selection your score is : ",score);
							   sel=NULL;

						    }
							else if(!sel->IsFilled()&&!rand->IsFilled())
							{
								score++;
							   correct++;
							   Delete(sel);
							   number_of_exited--;
							   pOut->PrintMessage2("right selection your score is : ",score);
							   sel=NULL;
							}
							else if(!SameColor(sel->GetCurrentColor(),rand->GetCurrentColor())&&sel->IsFilled()&&rand->IsFilled())
							{
								if(score!=0)
									score--;
								uncorrect++;
								pOut->PrintMessage2("not right selection...(try AGAIN) your score is : ",score);
								sel=NULL;
								lifes--;
							}
							else if(sel->IsFilled()&&!rand->IsFilled())
							{
								if(score!=0)
									score--;
								uncorrect++;
								pOut->PrintMessage2("not right selection...(try AGAIN) your score is : ",score);
								sel=NULL;
								lifes--;
							}
							else if(!sel->IsFilled()&&rand->IsFilled())
							{
								if(score!=0)
									score--;
								uncorrect++;
								pOut->PrintMessage2("not right selection...(try AGAIN) your score is : ",score);
								sel=NULL;
								lifes--;
							}
					
					}
					else
					{
						if(score!=0)
							score--;
					    uncorrect++;
						pOut->PrintMessage2("not right selection...(try AGAIN) your score is : ",score);
						sel=NULL;
						lifes--;
					}
				
					}
					while( number_of_exited!=0&&checkColor_Figure(GetType(rand),rand->GetCurrentColor(),rand)&&lifes!=0);
					}
					if(FigureList.size()!=0)
					{
				    rand=Random();
                    number_of_exited=rand->GetNumber();
				    Message(3,rand);
					}
				}
				while((actType==DRAWING_AREA||actType==EMPTY)&&(FigureList.size()!=0&&lifes!=0));

				if(actType==PC||actType==PF||actType==PFI)
					break;

				else if(actType==TO_DRAW)
				{
					FigureList.clear();
             	    pOut->CreateDrawToolBar();
					pOut->ClearStatusBar();
				    break;
				}

				if(lifes!=0)
				{
				pOut->PrintMessage("You Won... click any where to know your score  ");
				pIn->GetPointClicked(P.x,P.y);
				pOut->PrintMessage2("your final score is  :  ",score);
				pIn->GetPointClicked(P.x,P.y);
				pOut->PrintMessage2("your uncorrect selections is  :  ",uncorrect);
				pIn->GetPointClicked(P.x,P.y);
				pOut->PrintMessage2("your correct selections is  :  ",correct);
				break;
				}
				else
				{
					pOut->PrintMessage("You Lost... click any where to try again  ");
					pIn->GetPointClicked(P.x,P.y);
					break;
				}

			}
			
		case DRAWING_AREA:
			break;
		case STATUS:
			break;
		case EMPTY:
			break;
		case TO_DRAW:
			{
				FigureList.clear();
             	pOut->CreateDrawToolBar();
				break;
			}
		}
	}while(actType!=TO_DRAW||Switch);
}
PickAndHide::~PickAndHide(void)
{

}
