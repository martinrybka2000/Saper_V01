#include "stdafx.h"
#include "ChangeMenuCommand.h"


ChangeMenuCommand::ChangeMenuCommand(Menu* m, string what): menu_str(what)
{
	menu = m;
}


ChangeMenuCommand::~ChangeMenuCommand()
{
}
