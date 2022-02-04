#pragma once
#include "Command.h"
#include "Menu.h"

class Menu;

class BackCommand :
	public Command
{
	Menu *menu;

public:

	virtual void Execute() { menu->BackMenu(); };

	BackCommand(Menu* m);
	~BackCommand();
};

