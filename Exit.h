#pragma once
#include "Actions\Action.h"
#include "Select.h"
#include "Delete.h"
class Exit :
	public Action
{
public:
	Exit(ApplicationManager * pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~Exit();
};

