#pragma once
#include"Positionable.h"

class PositionCalculator
{
public:

	enum PositionNames
	{
		left_up,
		left_centre,
		left_down,
		right_up,
		right_centre,
		right_down,
		centre,
		centre_up,
		centre_down,
	};

private:


	struct PositionStruct
	{
		Positionable* object;
		sf::Vector2f border_shift;
		enum PositionNames position;
	};

	list<PositionStruct*> Struct_list;

	sf::RenderWindow* renderwindow;

public:

	void UpdatePositions();

	void AddObject(Positionable* pos, sf::Vector2f shift, enum PositionNames position) { 
		PositionStruct* new_struct = new PositionStruct;
		new_struct->object = pos;
		new_struct->border_shift = shift;
		new_struct->position = position;
		Struct_list.push_back(new_struct);
	};

	void DeleteObject() { Struct_list.pop_back(); };

	PositionCalculator(sf::RenderWindow* rw);
	virtual ~PositionCalculator();
};

