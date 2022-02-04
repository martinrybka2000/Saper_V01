#pragma once
class Positionable
{

public:

	virtual void SetOriginCenter() = 0;

	virtual void SetOrigin(sf::Vector2f origin) = 0;
	virtual void SetOrigin(float x, float y) = 0;

	virtual void SetPosition(sf::Vector2f position) = 0;
	virtual void SetPosition(float x, float y) = 0;

	virtual sf::Vector2f GetPosition() = 0;

	virtual sf::FloatRect GetBounds() = 0;

	Positionable();
	virtual ~Positionable();
};

