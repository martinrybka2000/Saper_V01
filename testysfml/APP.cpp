#include "stdafx.h"
#include "APP.h"
#include "NoCommand.h"

void APP::View(sf::RenderWindow *rw)
{
	rw->clear();

	menu->View(rw);
	_gamebuilder->View(rw);

	rw->display();
}

void APP::Upgrade(sf::Vector2i v)
{
	menu->Upgrade(v);
}

void APP::Upgrade(sf::Keyboard::Key k)
{
	menu->Upgrade(k);
}

void APP::Upgrade(sf::Mouse::Wheel wh)
{
	menu->Upgrade(wh);
}

void APP::Click(sf::Vector2i v, sf::Mouse::Button button)
{
	menu->Click(v);
}

APP::APP(sf::RenderWindow* rw)
{
	winsize = rw->getSize();

	menu = new Menu(winsize);
	_gamebuilder = new GameBuilder(winsize);
	game = new Game(_gamebuilder);

	NormalWall* Nwall = new NormalWall(winsize, "SETTINGS");

	menu->AddWall(new NormalWall(winsize, "MAIN MENU"));
	menu->AddWall(new ValueWall(winsize, "CUSTOM"));
	menu->AddWall(Nwall);

	menu->AddItem(new NormalItem("New Game", new NewGameCommand(game)), "MAIN MENU");
	menu->AddItem(new NormalItem("Resume", new ResumeCommand(game)), "MAIN MENU");
	menu->AddItem(new NormalItem("Settings", new ChangeMenuCommand(menu, "SETTINGS")), "MAIN MENU");
	menu->AddItem(new NormalItem("Exit", new ExitCommand(rw)), "MAIN MENU");

	menu->AddItem(new ColorItem(new NormalItem("Easy", new TypeCommand(_gamebuilder, 9, 9, 10)), Nwall), "SETTINGS");
	menu->AddItem(new ColorItem(new NormalItem("Medium", new TypeCommand(_gamebuilder, 16, 16, 40)), Nwall), "SETTINGS");
	menu->AddItem(new ColorItem(new NormalItem("Hard", new TypeCommand(_gamebuilder, 30, 16, 99)), Nwall), "SETTINGS");
	menu->AddItem(new ColorItem(new NormalItem("Custom", new ChangeMenuCommand(menu, "CUSTOM")), Nwall), "SETTINGS");
	menu->AddItem(new NormalItem("Back", new BackCommand(menu)), "SETTINGS");

	ValueItem* valueitem = new ValueItem("Mines", 10, 668);
	valueitem->SetCommmand(new CustomSetCommand(valueitem, _gamebuilder, &GameBuilder::SetMines));
	menu->AddItem(valueitem, "CUSTOM");

	ValueItem* valueitem2 = new ValueItem("Height", 9, 24);
	valueitem2->SetCommmand(new CustomSetCommand(valueitem2, _gamebuilder, &GameBuilder::SetY));
	menu->AddItem(valueitem2, "CUSTOM");

	ValueItem* valueitem3 = new ValueItem("Width", 9, 30);
	valueitem3->SetCommmand(new CustomSetCommand(valueitem3, _gamebuilder, &GameBuilder::SetX));	
	menu->AddItem(valueitem3, "CUSTOM");
	
	menu->AddItem(new NormalItem("Back Settings", new ChangeMenuCommand(menu, "SETTINGS")), "CUSTOM");
	menu->AddItem(new NormalItem("Back Main Menu", new BackCommand(menu)), "CUSTOM");
}


APP::~APP()
{
	delete menu;
	delete _gamebuilder;
	delete game;
}
