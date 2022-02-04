#pragma once

#include "NormalGenerator.h"

class GameBuilder
{
	int _x;
	int _y;
	int _mines;

	sf::Vector2u windowsize;

	sf::Font font;

	sf::Text tab[3];

public:

	void View(sf::RenderWindow* rw);

	void SetX(int x);
	void SetY(int y);
	void SetMines(int m);

	MinesGenerator* BuildAlgorythm() { return new NormalGenerator(_x, _y, _mines); };

	GameBuilder(sf::Vector2u winsize);
	~GameBuilder();
};

