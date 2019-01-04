#include "Exit.h"



Exit::Exit(ApplicationManager * pApp):Action(pApp){

}

void Exit::ReadActionParameters() {

}

void Exit::Execute(){
	pManager->ClearClipboard();
	pManager->Clean();
}

Exit::~Exit()
{
}
