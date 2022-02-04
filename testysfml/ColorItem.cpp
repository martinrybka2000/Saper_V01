#include "stdafx.h"
#include "ColorItem.h"

void ColorItem::Click()
{
	menuitem->Click();
	menuwall->ResetColors();
	menuitem->SetColor(sf::Color::Green);
}


ColorItem::ColorItem(MenuItem* mi, NormalWall* mw)
{
	menuitem = mi;
	menuwall = mw;
}


ColorItem::~ColorItem()
{
	delete menuitem;
	cout << "Usuwanie koloru" << endl << endl;
}
