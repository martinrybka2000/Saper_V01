#pragma once
#include "MenuItem.h"

class MenuWall
{
protected:

	list<MenuItem*> menulist;
	list<MenuItem*>::iterator menulist_it;
	list<MenuItem*>::iterator choosenOne;

	sf::CircleShape circle;

	sf::Font font;
	sf::Text Maintext;

	sf::Vector2u winsize;

	string Name;

public:

	void View(sf::RenderWindow *rw);

	void Click(sf::Vector2i v);
	void ResetColors();

	void AddMenuItem(MenuItem *mi);

	virtual void Upgrade(sf::Vector2i v) = 0;
	virtual void Upgrade(sf::Keyboard::Key k) = 0;
	virtual void Upgrade(sf::Mouse::Wheel wh) = 0;

	string GetName() { return Name; };

	MenuWall();
	virtual ~MenuWall();
};

