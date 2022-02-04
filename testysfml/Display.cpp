#include "stdafx.h"
#include "Display.h"

void Display::Update()
{
	renderwindow->clear(sf::Color(128, 128, 128)); // bug

	for (displaylist_it = displaylist.begin(); displaylist_it != displaylist.end(); displaylist_it++)
	{
		(*displaylist_it)->View(renderwindow);
	}

	renderwindow->display();
}

void Display::AttachDisplayed(Displayed* dis)
{
	displaylist.push_back(dis);
}

void Display::DeleteDisplayed()
{
	displaylist.clear();
}

Display::Display()
{
	
}

Display::Display(sf::RenderWindow* rw)
{
	renderwindow = rw;
}


Display::~Display()
{
	delete renderwindow;

	//for (displaylist_it = displaylist.begin(); displaylist_it != displaylist.end() ; displaylist_it++)
	//{
	//	delete *displaylist_it; // bug
	//}
	displaylist.clear();
}
