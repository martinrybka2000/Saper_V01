#pragma once
#include "GameContext.h"
#include "Gamealgorithm.h"

class Gamealgorithm;

class NormalContext :
	public GameContext
{
	friend Gamealgorithm;

	virtual void SetContext(sf::Vector2i position, enum InsideFieled value) {
		ContextField[position.x][position.y] = value;
		if (value != flag && value != covered) _covered--;
	};

public:

	NormalContext(int x, int y);
	~NormalContext();
};

