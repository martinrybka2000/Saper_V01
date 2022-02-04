#pragma once
#include "Command.h"
#include "Game.h"

class Game;

class ResumeCommand :
	public Command
{
	Game* game;

public:

	virtual void Execute() { game->Resume(); };

	ResumeCommand(Game* g);
	~ResumeCommand();
};

