#pragma once
#include "Command.h"

class MenuItem
{
protected:

	sf::Text text;
	sf::Font font;

	Command* com;

public:

	virtual void View(sf::RenderWindow *rw) { rw->draw(text); };

	virtual void SetPosition(sf::Vector2f v) { text.setPosition(v); }

	virtual void SetColor(sf::Color c) { text.setFillColor(c); }

	virtual void SetOrigin(float x, float y) { text.setOrigin(x, y); };

	virtual void SetCommmand(Command* c) { com = c; };

	virtual sf::Vector2f GetPosition() { return text.getPosition(); }

	virtual sf::String GetString() { return text.getString(); }

	virtual sf::FloatRect GetBounds() { return text.getGlobalBounds(); };

	virtual void Click() = 0;
	virtual void Upgrade(sf::Keyboard::Key key) = 0;
	virtual void Upgrade(sf::Mouse::Wheel wh) = 0;

	MenuItem();
	virtual ~MenuItem();
};

