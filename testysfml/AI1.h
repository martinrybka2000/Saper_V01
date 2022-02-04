#pragma once
#include "AbstractAI.h"
class AI1 :
	public AbstractAI
{
	virtual void CheckFlags(vector<vector<InsideFieled>> context);
	virtual void CheckUncover(vector<vector<InsideFieled>> context);

public:
	AI1();
	~AI1();
};

