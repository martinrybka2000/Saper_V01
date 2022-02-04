#pragma once
#include "Menu.h"
#include "NormaliItem.h"
#include "ColorItem.h"
#include "ValueItem.h"
#include "ExitCommand.h"
#include "ChangeMenuCommand.h"
#include "BackCommand.h"
#include "TypeCommand.h"
#include "NewGameCommand.h"
#include "ResumeCommand.h"
#include "CustomSetCommand.h"
#include "GameBuilder.h"
#include "ValueWall.h"
#include "Game.h"
#include "Controllable.h"


class APP: 
	public Controllable
{
	Menu* menu;
	GameBuilder* _gamebuilder;
	Game* game;

	sf::Vector2u winsize;

public:

	void View(sf::RenderWindow *rw);

	virtual void Upgrade(sf::Vector2i v);
	virtual void Upgrade(sf::Keyboard::Key k);
	virtual void Upgrade(sf::Mouse::Wheel wh);
	virtual void Click(sf::Vector2i v, sf::Mouse::Button button);

	APP(sf::RenderWindow* rw);
	~APP();
};

