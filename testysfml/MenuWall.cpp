#include "stdafx.h"
#include "MenuWall.h"

void MenuWall::AddMenuItem(MenuItem *mi)
{
	if (menulist.empty()) {

		sf::FloatRect rec = mi->GetBounds();
		mi->SetOrigin((rec.left + rec.width) / 2, (rec.top + rec.height / 2));
		mi->SetPosition(sf::Vector2f( static_cast<float> (winsize.x / 2), 160));

		menulist.push_back(mi);
		choosenOne = menulist.begin();
	}
	else {
		sf::FloatRect rec = mi->GetBounds();
		mi->SetOrigin((rec.left + rec.width) / 2, (rec.top + rec.height / 2));

		mi->SetPosition(menulist.back()->GetPosition() + sf::Vector2f(0, 34));
		menulist.push_back(mi);
	}
}

void MenuWall::View(sf::RenderWindow *rw)
{
	rw->draw(Maintext);

	for (menulist_it = menulist.begin(); menulist_it != menulist.end(); menulist_it++)
	{
		(*menulist_it)->View(rw);
	}

	if (!menulist.empty()) {
		sf::FloatRect rec = (*choosenOne)->GetBounds();
		circle.setPosition((*choosenOne)->GetPosition() - sf::Vector2f(rec.width / 2, rec.height / 2) - sf::Vector2f(15, -3));
		rw->draw(circle);
	}
}

void MenuWall::Click(sf::Vector2i v)
{
	for (menulist_it = menulist.begin(); menulist_it != menulist.end(); menulist_it++)
	{
		sf::FloatRect rec = (*menulist_it)->GetBounds();
		rec.left = 0;
		rec.width = static_cast<float> (winsize.x);

		if (rec.contains(static_cast<float> (v.x), static_cast<float>(v.y))) {
			(*menulist_it)->Click();
			break;
		}
	}
}

void MenuWall::ResetColors()
{
	for (menulist_it = menulist.begin(); menulist_it != menulist.end(); menulist_it++)
	{
		(*menulist_it)->SetColor(sf::Color::White);
	}
}

MenuWall::MenuWall()
{
}


MenuWall::~MenuWall()
{
}
