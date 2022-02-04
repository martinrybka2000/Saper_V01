#include "stdafx.h"
#include "TypeCommand.h"

void TypeCommand::Execute()
{
	gamebuilder->SetX(_x);
	gamebuilder->SetY(_y);
	gamebuilder->SetMines(_mines);
}



TypeCommand::TypeCommand(GameBuilder* _gamebuilder, int x, int y, int m): _x(x), _y(y), _mines(m)
{
	gamebuilder = _gamebuilder;
}


TypeCommand::~TypeCommand()
{
}
