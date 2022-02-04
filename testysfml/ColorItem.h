#pragma once
#include "MenuItem.h"
#include "NormalWall.h"

class NormalWall;

class ColorItem :
	public MenuItem
{
	MenuItem* menuitem;
	NormalWall* menuwall;

public:

	virtual void View(sf::RenderWindow *rw) { menuitem->View(rw); };

	virtual void SetPosition(sf::Vector2f v) { menuitem->SetPosition(v); }

	virtual void SetColor(sf::Color c) { menuitem->SetColor(c); }

	virtual void SetOrigin(float x, float y) { menuitem->SetOrigin(x, y); };

	virtual void SetCommmand(Command* c) { menuitem->SetCommmand(c); };

	virtual sf::Vector2f GetPosition() { return menuitem->GetPosition(); }

	virtual sf::String GetString() { return menuitem->GetString(); }

	virtual sf::FloatRect GetBounds() { return menuitem->GetBounds(); };

	virtual void Click();

	virtual void Upgrade(sf::Keyboard::Key key) { menuitem->Upgrade(key); };

	virtual void Upgrade(sf::Mouse::Wheel wh) { menuitem->Upgrade(wh); };

	ColorItem(MenuItem* mi, NormalWall* mw);
	~ColorItem();
};

