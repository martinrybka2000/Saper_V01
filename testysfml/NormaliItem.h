#pragma once
#include "MenuItem.h"


class NormalItem : 
	public MenuItem
{

public:

	virtual void Click() { com->Execute(); }
	virtual void Upgrade(sf::Keyboard::Key key) {};
	virtual void Upgrade(sf::Mouse::Wheel wh) {};

	NormalItem(string name, Command *c);
	~NormalItem();
};

