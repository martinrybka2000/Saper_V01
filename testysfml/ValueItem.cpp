#include "stdafx.h"
#include "ValueItem.h"

void ValueItem::Upgrade(sf::Keyboard::Key key)
{
	switch (key)
	{
	case sf::Keyboard::Left:
		if (_val > _min) {
			_val--;
			text.setString(string(_name + "  " + to_string(_val)));
			Click();
		}
		break;
	case sf::Keyboard::Right:
		if (_val < _max) {
			_val++;
			text.setString(string(_name + "  " + to_string(_val)));
			Click();
		}
		break;
	default:
		break;
	}
}

void ValueItem::Upgrade(sf::Mouse::Wheel wh)
{
	switch (wh)
	{
	case(sf::Mouse::Wheel::HorizontalWheel):
		if (_val < _max) {
			_val++;
			text.setString(string(_name + "  " + to_string(_val)));
			Click();
		}
		break;
	case(sf::Mouse::Wheel::VerticalWheel):
		if (_val > _min) {
			_val--;
			text.setString(string(_name + "  " + to_string(_val)));
			Click();
		}
		break;
	default:
		break;
	}
}

ValueItem::ValueItem(string name, const int min, const int max) : _max(max), _min(min), _val(min), _name(name)
{
	font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
	text.setFont(font);

	text.setFillColor(sf::Color::White);
	text.setCharacterSize(24);

	text.setString(string(name + "  " + to_string(min)));
}

ValueItem::ValueItem(string name, Command *c, const int min, const int max): _max(max), _min(min), _val(min) , _name(name)
{
	com = c;

	font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
	text.setFont(font);

	text.setFillColor(sf::Color::White);
	text.setCharacterSize(24);

	text.setString(string(name + "  " + to_string(min)));
}


ValueItem::~ValueItem()
{
	delete com;
}
