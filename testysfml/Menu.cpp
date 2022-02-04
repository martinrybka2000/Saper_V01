#include "stdafx.h"
#include "Menu.h"

void Menu::View(sf::RenderWindow *rw)
{
//	rw->draw(sprite);
	rw->draw(MainText);
	rw->draw(BorderText);

	if (*ChoosenOne) (*ChoosenOne)->View(rw);
}

void Menu::AddWall(MenuWall* wall)
{
	if (MenuWall_list.empty()) {
		MenuWall_list.push_back(wall);
		ChoosenOne = MenuWall_list.begin();
		Last = MenuWall_list.begin();
	}
	else MenuWall_list.push_back(wall);
}

void Menu::AddItem(MenuItem* _valueItem, string where)
{
	for (MenuWall_it = MenuWall_list.begin(); MenuWall_it != MenuWall_list.end(); MenuWall_it++)
	{
 		if (where == (*MenuWall_it)->GetName()) {
			(*MenuWall_it)->AddMenuItem(_valueItem);
			break;
		}
	}
}

void Menu::BackMenu()
{
	if (*Last) ChoosenOne = Last;
}

void Menu::ChangeMenu(string m)
{
	for (MenuWall_it = MenuWall_list.begin(); MenuWall_it != MenuWall_list.end(); MenuWall_it++)
	{
		if (m == (*MenuWall_it)->GetName()) {
			ChoosenOne = MenuWall_it;
			break;
		}
	}
}

void Menu::Upgrade(sf::Vector2i v)
{
	if (*ChoosenOne) (*ChoosenOne)->Upgrade(v);
}

void Menu::Upgrade(sf::Keyboard::Key k)
{
	if (*ChoosenOne) (*ChoosenOne)->Upgrade(k);
}

void Menu::Upgrade(sf::Mouse::Wheel wh)
{
	if (*ChoosenOne) (*ChoosenOne)->Upgrade(wh);
}

void Menu::Click(sf::Vector2i v)
{
	if (*ChoosenOne) (*ChoosenOne)->Click(v);
}

Menu::Menu(sf::Vector2u windowsize): winsize(windowsize)
{
	if (!texture.loadFromFile("saper.jpg")) cout << "brak pliku jpg";
	texture.setSmooth(true);

	sprite.setTexture(texture);

	font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
	MainText.setFont(font);
	BorderText.setFont(font);

	MainText.setFillColor(sf::Color::White);
	BorderText.setFillColor(sf::Color::White);

	MainText.setCharacterSize(36);
	BorderText.setCharacterSize(16);

	MainText.setString("**Saper_V.0.1**");
	BorderText.setString("|Created by Martin Rybka|");

	sf::FloatRect rec = MainText.getLocalBounds();
	MainText.setOrigin((rec.left + rec.width) / 2, (rec.top + rec.height / 2));
	MainText.setPosition(winsize.x / 2, 60);

}


Menu::~Menu()
{
	for (MenuWall_it = MenuWall_list.begin(); MenuWall_it != MenuWall_list.end(); MenuWall_it++)
	{
		delete *MenuWall_it;
	}	
}
