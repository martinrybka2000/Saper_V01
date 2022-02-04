#include "stdafx.h"
#include "AIControler.h"

void AIControler::Event(sf::Event* ev)
{
	controll->Click(sf::Vector2i(10, 10), sf::Mouse::Left);

	data = ai->TemplateMethod(gcontext->GetContext());

	if (data.state == uncover)
	{
		while (!data.flags_changes.empty()) {
			controll->Click(sf::Vector2i(10, 10), sf::Mouse::Right);
			data.flags_changes.pop();
		}
	}
}

AIControler::AIControler(Controllable* ca, sf::RenderWindow* rw)
{
	controll = ca;
	window = rw;

	ai = new AI1();

	data.state = flags;
}

AIControler::AIControler(Controllable* ca, sf::RenderWindow* rw, GameContext* gc)
{
	controll = ca;
	window = rw;
	gcontext = gc;

	ai = new AI1();

	data.state = flags;
}


AIControler::~AIControler()
{
}
