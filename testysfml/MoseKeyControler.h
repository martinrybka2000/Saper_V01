#pragma once
#include "Controler.h"
class MoseKeyControler :
	public Controler
{
	sf::Mouse mouse;
	sf::RenderWindow* window;

	sf::Mouse::Button button;

public:

	virtual void Event(sf::Event* ev);

	sf::Vector2i GetMousePos() { return mouse.getPosition(*window); };

	MoseKeyControler(Controllable* con, sf::RenderWindow *rw);
	~MoseKeyControler();
};

