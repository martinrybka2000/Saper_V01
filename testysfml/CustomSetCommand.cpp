#include "stdafx.h"
#include "CustomSetCommand.h"

//template <class Receiver>
void CustomSetCommand::Execute()
{
	int val = _valueItem->AskVal();

	(_gamebuilder->*_action) (val);
}

//template <class Receiver>
CustomSetCommand::CustomSetCommand(ValueItem* vi, GameBuilder* gb, Action a)
{
	_valueItem = vi;
	_gamebuilder = gb;
	_action = a;
}

//template <class Receiver>
CustomSetCommand::~CustomSetCommand()
{
}
