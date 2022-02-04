#include "stdafx.h"
#include "ValueWall.h"


void ValueWall::Upgrade(sf::Vector2i v)
{
	for (menulist_it = menulist.begin(); menulist_it != menulist.end(); menulist_it++)
	{
		sf::FloatRect rec = (*menulist_it)->GetBounds();
		rec.left = 0;
		rec.width = static_cast<float> (winsize.x);

		if (rec.contains(static_cast<float> (v.x), static_cast<float>(v.y))) {
			choosenOne = menulist_it;
			break;
		}
	}
}

void ValueWall::Upgrade(sf::Keyboard::Key k)
{
	switch (k)
	{
	case(sf::Keyboard::Key::Down):
		choosenOne++;
		if (choosenOne == menulist.end()) choosenOne = menulist.begin();
		break;
	case(sf::Keyboard::Key::Up):
		for (size_t i = 0; i < (menulist.size() - 1); i++)
		{
			choosenOne++;
			if (choosenOne == menulist.end()) choosenOne = menulist.begin();
		}
		break;
	case(sf::Keyboard::Key::Enter):
		(*choosenOne)->Click();
		break;
	default:
		(*choosenOne)->Upgrade(k);
		break;
	}
}

void ValueWall::Upgrade(sf::Mouse::Wheel wh)
{
	(*choosenOne)->Upgrade(wh);
}

ValueWall::ValueWall(sf::Vector2u windowsize, string name)
{
	winsize = windowsize;
	Name = name;

	circle.setFillColor(sf::Color::White);
	circle.setRadius(6);

	font.loadFromFile("C:/Windows/Fonts/Arial.ttf");

	Maintext.setFont(font);
	Maintext.setFillColor(sf::Color::Red);
	Maintext.setCharacterSize(30);
	Maintext.setString(name);

	sf::FloatRect rec = Maintext.getLocalBounds();
	Maintext.setOrigin((rec.left + rec.width) / 2, (rec.top + rec.height / 2));
	Maintext.setPosition(static_cast<float> (winsize.x / 2), 110);
}


ValueWall::~ValueWall()
{
	for (menulist_it = menulist.begin(); menulist_it != menulist.end(); menulist_it++)
	{
		delete *menulist_it;
	}
}
