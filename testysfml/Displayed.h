#pragma once


class Displayed
{

public:

	virtual void Update() = 0;

	virtual void View(sf::RenderWindow* rw) = 0;

	Displayed();
	virtual ~Displayed();
};

