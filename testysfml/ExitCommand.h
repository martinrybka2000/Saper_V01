#pragma once
#include "Command.h"


class ExitCommand :
	public Command
{

	sf::RenderWindow* _renderwindow;

public:

	virtual void Execute() { _renderwindow->close(); }

	ExitCommand(sf::RenderWindow* rw);
	~ExitCommand();
};

