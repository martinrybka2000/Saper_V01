#pragma once
#include "Command.h"
#include "GameBuilder.h"

class TypeCommand :
	public Command
{
	GameBuilder* gamebuilder;

	int _x;
	int _y;
	int _mines;

public:

	virtual void Execute();

	TypeCommand(GameBuilder* _gamebuilder, int x, int y, int m);
	~TypeCommand();
};

