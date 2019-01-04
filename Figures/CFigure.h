#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	static int nl,nc,nr,nt;
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);

	virtual void increase () = 0;
	virtual void decrease () =0;
	virtual int GetNumber()const=0;
	int GetNumOfLines ()const;
	int GetNumOfCircles ()const;
	int GetNumOfRectangles ()const;
	int GetNumOfTriangles ()const;

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	virtual void set_to_paste(Point p,Point d)=0;
	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	
	virtual int GetID () const =0;
	virtual bool OnFigure(Point)const = 0;
	virtual Point get_corner1()=0;
	virtual CFigure* GetCopy ()=0;
	

	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	
	virtual color GetCurrentColor ()const;
	bool IsFilled()const;
	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
	virtual ~CFigure();
};

#endif