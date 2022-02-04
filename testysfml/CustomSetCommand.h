#pragma once
#include "Command.h"
#include "ValueItem.h"
#include "GameBuilder.h"

class ValueItem;

//template <class Receiver>
class CustomSetCommand :
	public Command
{
public:
	typedef void (GameBuilder::* Action) (int);

	virtual void Execute();

	CustomSetCommand(ValueItem* vi, GameBuilder* gb, Action a);
	~CustomSetCommand();

private:

	Action _action;

	ValueItem* _valueItem;
	GameBuilder* _gamebuilder;

	void(*fun) (int);
};

