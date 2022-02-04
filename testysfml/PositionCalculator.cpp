#include "stdafx.h"
#include "PositionCalculator.h"

void PositionCalculator::UpdatePositions()
{
	list<PositionStruct*>::iterator it;

	sf::Vector2u wsize = renderwindow->getSize();
	

	for (it = Struct_list.begin(); it != Struct_list.end(); it++)
	{
		sf::FloatRect bounds = (*it)->object->GetBounds();

		switch ((*it)->position)
		{
		case left_up:
			(*it)->object->SetPosition((*it)->border_shift);
			break;

		case left_centre:
			(*it)->object->SetOrigin(0, bounds.height / 2);
			(*it)->object->SetPosition((*it)->border_shift.x, wsize.y / 2);
			break;

		case left_down:
			(*it)->object->SetOrigin(0, bounds.height);
			(*it)->object->SetPosition((*it)->border_shift.x, wsize.y - (*it)->border_shift.y);
			break;

		case centre:
			(*it)->object->SetOriginCenter();
			(*it)->object->SetPosition(wsize.x / 2, wsize.y / 2);
			break;

		case centre_up:
			(*it)->object->SetOrigin(bounds.width / 2, 0);
			(*it)->object->SetPosition(wsize.x / 2, (*it)->border_shift.y);
			break;

		case centre_down:
			(*it)->object->SetOrigin(bounds.width / 2, bounds.height);
			(*it)->object->SetPosition(wsize.x / 2, wsize.y - (*it)->border_shift.y);
			break;

		case right_up:
			(*it)->object->SetOrigin(bounds.width, 0);
			(*it)->object->SetPosition(wsize.x - (*it)->border_shift.x, (*it)->border_shift.y);
			break;

		case right_centre:
			(*it)->object->SetOrigin(bounds.width, bounds.height / 2);
			(*it)->object->SetPosition(wsize.x - (*it)->border_shift.x, wsize.y / 2);
			break;

		case right_down:
			(*it)->object->SetOrigin(bounds.width, bounds.height);
			(*it)->object->SetPosition(sf::Vector2f(wsize.x, wsize.y) - (*it)->border_shift);
			break;

		default:
			break;
		}
	}
}

PositionCalculator::PositionCalculator(sf::RenderWindow* rw)
{
	renderwindow = rw;
}


PositionCalculator::~PositionCalculator()
{
}
