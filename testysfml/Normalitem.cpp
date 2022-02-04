#include "stdafx.h"
#include "NormaliItem.h"


NormalItem::NormalItem(string name, Command *c)
{
	com = c;

	font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
	text.setFont(font);

	text.setFillColor(sf::Color::White);
	text.setCharacterSize(24);

	text.setString(name);
}


NormalItem::~NormalItem()
{
	delete com;
	cout << "Usuwanie " << endl << endl;
}
