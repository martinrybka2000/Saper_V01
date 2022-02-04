#include "stdafx.h"
#include "AbstractAI.h"

AIdata& AbstractAI::TemplateMethod(vector<vector<InsideFieled>> context)
{
	switch (data.state)
	{
	case (flag):

		CheckFlags(context);
		data.state = uncover;

		return data;

		break;

	case uncover:

		CheckUncover(context);
		data.state = ended;

		return data;

		break;
	default:
		break;
	}


	return data;
}

AbstractAI::AbstractAI()
{
	data.state = ended;
}


AbstractAI::~AbstractAI()
{
}
