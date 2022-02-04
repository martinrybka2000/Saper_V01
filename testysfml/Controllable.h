#pragma once
class Controllable
{
public:

	virtual void Upgrade(sf::Vector2i v) = 0;
	virtual void Upgrade(sf::Keyboard::Key k) = 0;
	virtual void Upgrade(sf::Mouse::Wheel wh) = 0;
	virtual void Click(sf::Vector2i v, sf::Mouse::Button button) = 0;

	Controllable();
	virtual ~Controllable();
};

