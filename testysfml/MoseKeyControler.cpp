#include "stdafx.h"
#include "MoseKeyControler.h"

void MoseKeyControler::Event(sf::Event* ev)
{
	switch (ev->type)
	{
	case(sf::Event::MouseMoved):
		controll->Upgrade(mouse.getPosition(*window));
		break;

	case(sf::Event::MouseButtonPressed):
		if (mouse.isButtonPressed(sf::Mouse::Left)) button = sf::Mouse::Left;
		else if (mouse.isButtonPressed(sf::Mouse::Right)) button = sf::Mouse::Right;
		break;

	case(sf::Event::MouseButtonReleased):
		if (button == sf::Mouse::Left) {
			controll->Click(mouse.getPosition(*window), sf::Mouse::Left);
			button = sf::Mouse::Middle;
		}
		else if (button == sf::Mouse::Right) {
			controll->Click(mouse.getPosition(*window), sf::Mouse::Right);
			button = sf::Mouse::Middle;
		}
		break;

	case(sf::Event::KeyPressed):
		controll->Upgrade(ev->key.code);
		break;

	case (sf::Event::MouseWheelScrolled):
		if (ev->mouseWheelScroll.delta > 0)
			controll->Upgrade(sf::Mouse::VerticalWheel);
		else if (ev->mouseWheelScroll.delta < 0)
			controll->Upgrade(sf::Mouse::HorizontalWheel);
		break;
	default:
		break;
	}
}

MoseKeyControler::MoseKeyControler(Controllable* con, sf::RenderWindow *rw)
{
	controll = con;
	window = rw;
}


MoseKeyControler::~MoseKeyControler()
{
}

