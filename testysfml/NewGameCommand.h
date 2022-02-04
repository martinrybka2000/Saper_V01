#pragma once
#include "Command.h"
#include "Game.h"

class Game;

class NewGameCommand :
	public Command
{

	Game* game;

public:

	virtual void Execute() { game->NewGame(); };

	NewGameCommand(Game* g);
	~NewGameCommand();
};

