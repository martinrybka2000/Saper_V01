#include "stdafx.h"
#include "Square.h"


Square::Square(sf::Vector2f position)
{
	rec.setPosition(position);
	rec.setSize(sf::Vector2f(square_size, square_size));
	rec.setFillColor(sf::Color::Green);
	//rec.setOutlineColor(sf::Color::White);
//	rec.setOutlineThickness(5);
}

Square::Square(sf::Vector2f position, sf::Texture* texture, sf::Color texturecolor)
{
	rec.setPosition(position);
	rec.setTexture(texture, true);
	rec.setFillColor(texturecolor);
	rec.setSize(sf::Vector2f(square_size, square_size));
}


Square::~Square()
{
}
