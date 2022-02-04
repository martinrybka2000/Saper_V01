#pragma once
#include "WindowDecorator.h"
class PictureDecorator :
	public WindowDecorator
{
	sf::RectangleShape picture;
	sf::Texture texture;

	int _offset;

public:

	virtual void Update() { WindowDecorator::Update(); };
	virtual void View(sf::RenderWindow* rw) { 
		rw->draw(picture);
		WindowDecorator::View(rw); 	
	};
	//********************************************************

	//*********************Positionable**********************
	virtual void SetOriginCenter();

	virtual void SetOrigin(sf::Vector2f origin);
	virtual void SetOrigin(float x, float y);

	virtual void SetPosition(sf::Vector2f position);
	virtual void SetPosition(float x, float y);

	virtual sf::Vector2f GetPosition();
	virtual sf::FloatRect GetBounds();
	//***********************************************************

	virtual void SetVal(string val) { WindowDecorator::SetVal(val); };
	virtual void SetSize(sf::Vector2f size);

	PictureDecorator(ViewWindow* window, int offset, string filename);
	~PictureDecorator();
};

