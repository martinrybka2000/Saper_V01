#pragma once
#include "Command.h"
#include "Menu.h"

class Menu;

class ChangeMenuCommand :
	public Command
{
	Menu* menu;
	string menu_str;

public:

	virtual void Execute() { menu->ChangeMenu(menu_str); };

	ChangeMenuCommand(Menu* m, string what);
	~ChangeMenuCommand();
};

