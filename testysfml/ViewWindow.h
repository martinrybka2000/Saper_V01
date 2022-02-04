#pragma once
#include "Displayed.h"
#include "Positionable.h"

class ViewWindow:
	public Displayed, public Positionable
{
protected:

	sf::RectangleShape rec;

public:

//*****************Displayed**************************
	virtual void Update() = 0;
	virtual void View(sf::RenderWindow* rw) = 0;
//********************************************************

//*********************Positionable**********************
	virtual void SetOriginCenter() = 0;

	virtual void SetOrigin(sf::Vector2f origin) = 0;
	virtual void SetOrigin(float x, float y) = 0;

	virtual void SetPosition(sf::Vector2f position) = 0;
	virtual void SetPosition(float x, float y) = 0;

	virtual sf::Vector2f GetPosition() = 0;
	virtual sf::FloatRect GetBounds() = 0;
//***********************************************************

	virtual void SetVal(string val) = 0;
	virtual void SetSize(sf::Vector2f size) = 0;

	void SetColor(sf::Color color) { rec.setFillColor(color); };

	ViewWindow();
	virtual ~ViewWindow();
};

