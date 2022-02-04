#include "stdafx.h"
#include "GameBuilder.h"

void GameBuilder::SetX(int x)
{
	_x = x;
	tab[0].setString(string("Width = " + to_string(_x)));
}

void GameBuilder::SetY(int y)
{
	_y = y;
	tab[1].setString(string("Height = " + to_string(_y)));
}

void GameBuilder::SetMines(int m)
{
	_mines = m;
	tab[2].setString(string("Mines = " + to_string(_mines)));
}

void GameBuilder::View(sf::RenderWindow* rw)
{
	rw->draw(tab[0]);
	rw->draw(tab[1]);
	rw->draw(tab[2]);
}

GameBuilder::GameBuilder(sf::Vector2u winsize): _x(9), _y(9), _mines(10), windowsize(winsize)
{
	font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
	tab[0].setFont(font);
	tab[1].setFont(font);
	tab[2].setFont(font);

	tab[0].setFillColor(sf::Color::White);
	tab[1].setFillColor(sf::Color::White);
	tab[2].setFillColor(sf::Color::White);

	tab[0].setCharacterSize(18);
	tab[1].setCharacterSize(18);
	tab[2].setCharacterSize(18);

	tab[0].setString(string("Width = " + to_string(_x)));
	tab[1].setString(string("Height = " + to_string(_y)));
	tab[2].setString(string("Mines = " + to_string(_mines)));

	tab[0].setPosition(0, static_cast<float>(windowsize.y) - tab[0].getCharacterSize() - 5);
	tab[1].setPosition(100, static_cast<float>(windowsize.y) - tab[1].getCharacterSize() - 5);
	tab[2].setPosition(200, static_cast<float>(windowsize.y) - tab[2].getCharacterSize() - 5);
}


GameBuilder::~GameBuilder()
{
}
