#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();		

	window* CreateWind(int, int, int , int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar

	void CreateColorToolBar() const;
	void CreateColorToolBar(int ) const;
	void ClearToolBar()const;
	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	
	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a rectangle
	void DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected=false) const; //Draw Line
	void DrawTrian(Point P1,Point P2,Point P3, GfxInfo TrianGfxInfo, bool selected=false) const;  //Draw Triangle
	void DrawCirc(Point P1,Point P2, GfxInfo CircGfxInfo, bool selected=false) const;  //Draw Circle

	///Make similar functions for drawing all other figures.
	
	void PrintMessage(string msg) const;	//Print a message on Status bar
	void PrintMessage2(string msg1,int msg) const;


	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width


	void ChangeDrawColor(ActionType);
	void ChangeFillColor(ActionType);
	
	~Output();
};

#endif