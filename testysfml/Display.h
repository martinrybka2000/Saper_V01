#pragma once
#include "Displayed.h"


class Display
{
	list<Displayed*> displaylist;
	list<Displayed*>::iterator displaylist_it;

	sf::RenderWindow* renderwindow;

public:

	void Update();
	void AttachDisplayed(Displayed* dis);
	void DeleteDisplayed();

	void SetRenderWindow(sf::RenderWindow* rw) { renderwindow = rw; }

	Display();
	Display(sf::RenderWindow* rw);
	~Display();
};

