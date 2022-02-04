#include "stdafx.h"
#include "PictureDecorator.h"

void PictureDecorator::SetOriginCenter() 
{ 
	sf::FloatRect rec = this->GetBounds();
	sf::FloatRect rec2 = picture.getLocalBounds();

	WindowDecorator::SetOrigin(rec.width / 2, rec.height / 2);

	picture.setOrigin( -((rec.width / 2) - rec2.width), rec.height / 2);
};

void PictureDecorator::SetOrigin(sf::Vector2f origin) 
{ 
	sf::FloatRect rec = this->GetBounds();
	sf::FloatRect rec2 = picture.getLocalBounds();
	sf::FloatRect rec3 = WindowDecorator::GetBounds();

	WindowDecorator::SetOrigin(origin);

	picture.setOrigin(-(rec.width - rec2.width - origin.x) , origin.y);
};

void PictureDecorator::SetOrigin(float x, float y) 
{ 
	sf::FloatRect rec = this->GetBounds();
	sf::FloatRect rec2 = picture.getLocalBounds();
	sf::FloatRect rec3 = WindowDecorator::GetBounds();

	WindowDecorator::SetOrigin(x, y);

	picture.setOrigin(-(rec.width - rec2.width - x), y);
};

void PictureDecorator::SetPosition(sf::Vector2f position) 
{ 
	WindowDecorator::SetPosition(position);
	picture.setPosition(position);
};

void PictureDecorator::SetPosition(float x, float y) 
{
	WindowDecorator::SetPosition(x,y);
	picture.setPosition(x, y);
};

sf::Vector2f PictureDecorator::GetPosition() 
{ 
	return WindowDecorator::GetPosition();
};

void PictureDecorator::SetSize(sf::Vector2f size)
{
	WindowDecorator::SetSize(size);

	picture.setSize(sf::Vector2f(size.y,size.y));
}

sf::FloatRect PictureDecorator::GetBounds() 
{ 
	sf::FloatRect rec = WindowDecorator::GetBounds();
	sf::FloatRect rec2 = picture.getLocalBounds();

	rec.width += _offset + rec2.left + rec2.width;

	return rec;
};

PictureDecorator::PictureDecorator(ViewWindow* window, int offset, string filename): _offset(offset)
{
	_window = window;

	texture.loadFromFile(filename);

	picture.setTexture(&texture);
}


PictureDecorator::~PictureDecorator()
{
}
