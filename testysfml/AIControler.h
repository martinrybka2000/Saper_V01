#pragma once
#include "Controler.h"
#include "GameContext.h"
#include "AbstractAI.h"
#include "AI1.h"

class AIControler :
	public Controler
{
	GameContext* gcontext;
	AbstractAI* ai;
	AIdata data;

	sf::Mouse mouse;
	sf::RenderWindow* window;

public:

	virtual void Event(sf::Event* ev);

	void SetContext(GameContext* gc) { gcontext = gc; }

	AIControler(Controllable* ca, sf::RenderWindow* rw);
	AIControler(Controllable* ca, sf::RenderWindow* rw, GameContext* gc);
	~AIControler();
};

