#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 60;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 10;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearToolBar()const
{
	GfxInfo gfxInfo;
	Point P1, P2;
	P1.x=0;P1.y=0;
	P2.x=UI.width;P2.y=UI.ToolBarHeight;
	gfxInfo.DrawClr = WHITE;	//any color for border
	gfxInfo.FillClr = WHITE;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled

	DrawRect(P1, P2, gfxInfo, false);
}

/////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;
	ClearToolBar();

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_LINE]="images\\MenuItems\\line.jpg";
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\rect.jpg";
	MenuItemImages[ITM_TRIAN] = "images\\MenuItems\\triangle.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\circle.jpg";
	MenuItemImages[DRAW_CLR] = "images\\MenuItems\\st3.jpg";
	MenuItemImages[FILL_CLR] = "images\\MenuItems\\fillc.jpg";
	MenuItemImages[ITM_SELEC] = "images\\MenuItems\\Select.jpg";
	MenuItemImages[MOVE1] = "images\\MenuItems\\move.jpg";
	MenuItemImages[COPY1] = "images\\MenuItems\\copy.jpg";
	MenuItemImages[CUT1] = "images\\MenuItems\\cut.jpg";
	MenuItemImages[PASTE1] = "images\\MenuItems\\PASTE.jpg";
	MenuItemImages[DEL1] = "images\\MenuItems\\DELETE.jpg";
	MenuItemImages[SAVE1] = "images\\MenuItems\\save.jpg";
	MenuItemImages[LOAD1] = "images\\MenuItems\\load.jpg";
	MenuItemImages[PLAY] = "images\\MenuItems\\playm.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\exit2.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateColorToolBar() const
{
	ClearToolBar();
	///TODO: write code to create Play mode menu
	string MenuItemImages[COLOR_ITM_COUNT];
	MenuItemImages[ITM_BLACK]="images\\MenuItems\\black.jpg";
	MenuItemImages[ITM_WHITE] = "images\\MenuItems\\white.jpg";
	MenuItemImages[ITM_RED] = "images\\MenuItems\\red.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\green.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\blue.jpg";
	MenuItemImages[ITM_BACK] = "images\\MenuItems\\back.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<COLOR_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
}
/////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateColorToolBar(int a) const
{
	if (a==1)
		UI.InterfaceMode=MODE_DRAW_COLOR;
	else
		UI.InterfaceMode=MODE_FILL_COLOR;
	ClearToolBar();
	///TODO: write code to create Play mode menu
	string MenuItemImages[COLOR_ITM_COUNT];
	MenuItemImages[ITM_BLACK]="images\\MenuItems\\black.jpg";
	MenuItemImages[ITM_WHITE] = "images\\MenuItems\\white.jpg";
	MenuItemImages[ITM_RED] = "images\\MenuItems\\red.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\green.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\blue.jpg";
	MenuItemImages[ITM_BACK] = "images\\MenuItems\\back.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<COLOR_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	//Draw a line under the toolbar
	//pWind->SetPen(RED, 3);
	//pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	
}
/////////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode=MODE_PLAY;
	ClearToolBar();
	///TODO: write code to create Play mode menu
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[PICK_FIGURE]="images\\MenuItems\\pshape.jpg";
	MenuItemImages[PICK_COLOR] = "images\\MenuItems\\pdraw.jpg";
	MenuItemImages[PICK_FILLED] = "images\\MenuItems\\pcolor.jpg";
	MenuItemImages[DRAW] = "images\\MenuItems\\drawm.jpg";
	MenuItemImages[END] = "images\\MenuItems\\exit2.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}

void Output::PrintMessage2(string msg1,int msg) const
{
	int x=10,y=UI.height - (int)(UI.StatusBarHeight/1.5);
	ClearStatusBar();
	PrintMessage(msg1);
	pWind->GetStringSize(x,y,msg1);

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   


	pWind->DrawInteger(x, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drwawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}
////////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = LineGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	style = FRAME;

	
	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);
	
}
////////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawTrian(Point P1,Point P2,Point P3, GfxInfo TrianGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = TrianGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (TrianGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(TrianGfxInfo.FillClr);
	}
	else	
		style = FRAME;
	
	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
	
}
////////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawCirc(Point P1,Point P2, GfxInfo CircGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = CircGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (CircGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(CircGfxInfo.FillClr);
	}
	else	
		style = FRAME;
	int R=(int)sqrt(pow((P1.x-P2.x),2)+pow((P1.y-P2.y),2));
	
	pWind->DrawCircle(P1.x, P1.y, R, style);

}
//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

void Output::ChangeDrawColor(ActionType ActType2)
{
	switch (ActType2)
	{
	case SET_BLACK:
		UI.DrawColor=BLACK;
		CreateDrawToolBar();
		break;
	case SET_BLUE:
		UI.DrawColor=BLUE;
		CreateDrawToolBar();
		break;
	case SET_WHITE:
		UI.DrawColor=WHITE;
		CreateDrawToolBar();
		break;
	case SET_RED:
		UI.DrawColor=RED;
		CreateDrawToolBar();
		break;
	case SET_GREEN:
		UI.DrawColor=GREEN;
		CreateDrawToolBar();
		break;
	
	}

}

void Output::ChangeFillColor(ActionType ActType3)
{
	UI.filled_OR_not=true;
	switch (ActType3)
	{
	case SET_BLACK:
		UI.FillColor=BLACK;
		CreateDrawToolBar();
		break;
	case SET_BLUE:
		UI.FillColor=BLUE;
		CreateDrawToolBar();
		break;
	case SET_WHITE:
		UI.FillColor=WHITE;
		CreateDrawToolBar();
		break;
	case SET_RED:
		UI.FillColor=RED;
		CreateDrawToolBar();
		break;
	case SET_GREEN:
		UI.FillColor=GREEN;
		CreateDrawToolBar();
		break;
	case EMPTY:
		UI.filled_OR_not=false;
		CreateDrawToolBar();
		break;
	case DRAWING_AREA:
		UI.filled_OR_not=false;
		CreateDrawToolBar();
		break;

		
	}
}