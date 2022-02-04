#pragma once
#include "MenuWall.h"


class NormalWall:
	public MenuWall
{
public:

	virtual void Upgrade(sf::Vector2i v);
	virtual void Upgrade(sf::Keyboard::Key k);
	virtual void Upgrade(sf::Mouse::Wheel wh);

	NormalWall(sf::Vector2u windowsize, string name);
	~NormalWall();
};

