#pragma once
#include "Controllable.h"

class Controler
{
protected:

	Controllable *controll;

public:

	virtual void Event(sf::Event* ev) = 0;

	Controler();
	virtual ~Controler();
};

