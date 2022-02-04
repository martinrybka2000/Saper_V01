#pragma once
#include "MenuWall.h"

class Menu
{
	list<MenuWall*> MenuWall_list;
	list<MenuWall*>::iterator MenuWall_it;
	list<MenuWall*>::iterator ChoosenOne;
	list<MenuWall*>::iterator Last;

	sf::Text MainText;
	sf::Text BorderText;

	sf::Font font;

	sf::Sprite sprite;
	sf::Texture texture;

	sf::Vector2f winsize;

public:

	void View(sf::RenderWindow *rw);

	void AddWall(MenuWall* wall);
	void AddItem(MenuItem* _valueItem, string where);

	void BackMenu();
	void ChangeMenu(string m);

	void Upgrade(sf::Vector2i v);
	void Upgrade(sf::Keyboard::Key k);
	void Upgrade(sf::Mouse::Wheel wh);
	void Click(sf::Vector2i v);

	Menu(sf::Vector2u windowsize);
	~Menu();
};

