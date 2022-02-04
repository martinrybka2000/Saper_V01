#pragma once
#include "ViewWindow.h"
#include "Display.h"

class ValueWindow :
	public ViewWindow
{
	Display* display;

	sf::Text text;
	sf::Font font;

	string value;

	void SetTextOriginCentre() {
		sf::FloatRect bounds = text.getLocalBounds();
		text.setOrigin((bounds.left + bounds.width) / 2, (bounds.top + bounds.height / 2));
	};

public:

	virtual void Update() { display->Update(); };
	virtual void View(sf::RenderWindow* rw) {
		rw->draw(rec);
		rw->draw(text); 
	};

	virtual void SetOriginCenter() {
		sf::Vector2f size = rec.getSize();
		size.x /= 2;
		size.y /= 2;
		rec.setOrigin(size);
	};

	virtual void SetOrigin(sf::Vector2f origin) { rec.setOrigin(origin); };
	virtual void SetOrigin(float x, float y) { rec.setOrigin(x, y); };

	virtual sf::Vector2f GetPosition() { return rec.getPosition(); };
	virtual sf::FloatRect GetBounds() { return rec.getLocalBounds(); };

	virtual void SetPosition(sf::Vector2f position);
	virtual void SetPosition(float x, float y);

	virtual void SetVal(string val);
	virtual void SetSize(sf::Vector2f size);

	ValueWindow(Display* dis, string val);
	~ValueWindow();
};

