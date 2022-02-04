#pragma once
#include "MenuItem.h"
class ValueItem :
	public MenuItem
{
	int _val;
	const int _min;
	const int _max;

	string _name;

public:

	int AskVal() { return _val; }

	virtual void Click() { com->Execute(); }
 	virtual void Upgrade(sf::Keyboard::Key key);
	virtual void Upgrade(sf::Mouse::Wheel wh);

	ValueItem(string name, const int min, const int max);
	ValueItem(string name, Command *c, const int min, const int max);
	~ValueItem();
};

