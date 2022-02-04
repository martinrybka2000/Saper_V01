#include "stdafx.h"
#include "ValueWindow.h"

void ValueWindow::SetVal(string val)
{ 
	text.setString(val); 
	SetTextOriginCentre();
	sf::FloatRect bounds = text.getLocalBounds();
	if (bounds.width > rec.getSize().x) rec.setSize(sf::Vector2f(bounds.width - rec.getSize().x, rec.getSize().y));
}

void ValueWindow::SetSize(sf::Vector2f size)
{ 
	text.setCharacterSize(static_cast<int> (size.y - 1)); 
	SetTextOriginCentre();
	rec.setSize(size); 
}

void ValueWindow::SetPosition(sf::Vector2f position)
{ 
	rec.setPosition(position); 
	sf::FloatRect bounds = rec.getLocalBounds();
	sf::Vector2f rec_position = rec.getPosition();
	sf::Vector2f rec_origin = rec.getOrigin();
	text.setPosition(rec_position.x - rec_origin.x + (bounds.width / 2), rec_position.y - rec_origin.y + (bounds.height / 2));
};

void ValueWindow::SetPosition(float x, float y)
{
	rec.setPosition(x, y);
	sf::FloatRect bounds = rec.getLocalBounds();
	sf::Vector2f rec_position = rec.getPosition();
	sf::Vector2f rec_origin = rec.getOrigin();
	text.setPosition(rec_position.x - rec_origin.x + (bounds.width / 2), rec_position.y - rec_origin.y + (bounds.height / 2));
}

ValueWindow::ValueWindow(Display* dis, string val)
{
	display = dis;

	font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
	text.setFont(font);

	text.setFillColor(sf::Color::Black);
	text.setString(val);

	SetTextOriginCentre();

	//text.setCharacterSize(24);	
}


ValueWindow::~ValueWindow()
{
}
