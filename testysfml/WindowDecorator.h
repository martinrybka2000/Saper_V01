#pragma once
#include "ViewWindow.h"
class WindowDecorator :
	public ViewWindow
{
protected:

	ViewWindow * _window;

public:

	virtual void Update() { _window->Update(); };
	virtual void View(sf::RenderWindow* rw) { _window->View(rw); };
	//********************************************************

	//*********************Positionable**********************
	virtual void SetOriginCenter() { _window->SetOriginCenter(); };

	virtual void SetOrigin(sf::Vector2f origin) { _window->SetOrigin(origin); };
	virtual void SetOrigin(float x, float y) { _window->SetOrigin(x,y); };

	virtual void SetPosition(sf::Vector2f position) { _window->SetPosition(position); };
	virtual void SetPosition(float x, float y) { _window->SetPosition(x,y); };

	virtual sf::Vector2f GetPosition() { return _window->GetPosition(); };
	virtual sf::FloatRect GetBounds() { return _window->GetBounds(); };
	//***********************************************************

	virtual void SetVal(string val) { _window->SetVal(val); };
	virtual void SetSize(sf::Vector2f size) { _window->SetSize(size); };

	WindowDecorator();
	virtual ~WindowDecorator();
};

