#pragma once
#include "Timer.h"
#include "Gamealgorithm.h"
#include "GameBuilder.h"
#include "Controler.h"
#include "PositionCalculator.h"
#include "MoseKeyControler.h"
#include "AIControler.h"
#include "PictureDecorator.h"

class Game
{
	Timer* timer;
	Gamealgorithm* gamealgorithm;
	MinesGenerator* minesgenerator;
	GameBuilder* gamebuilder;
	Controler* controler;
	Display* display;
	ViewWindow* windows[2];
	PositionCalculator* positioncalculator;

	sf::RenderWindow* renderwindow;

	void Event(sf::RenderWindow* rw);

	enum State state;

	string windowStr[2];

public:

	void NewGame();
	void Resume();
	void Delete() {};

	Game(GameBuilder* gb);
	~Game();
};

