#pragma once
//#include "Gamealgorithm.h"

//class Gamealgorithm;

enum InsideFieled { covered = -2, mine, empty, one, two, three, four, five, six, seven, eight, flag };

class GameContext
{
protected:

	vector<vector<InsideFieled>> ContextField;

	sf::Vector2i size;
	int _covered;

	virtual void SetContext(sf::Vector2i position, enum InsideFieled value) = 0;

public:

	vector<vector<InsideFieled>> GetContext() { return ContextField; };
	InsideFieled GetContext(int x, int y) { return ContextField[x][y]; };
	InsideFieled GetContext(sf::Vector2i v) { return ContextField[v.x][v.y]; };
	int GetCovered() { return _covered; }

	GameContext();
	virtual ~GameContext();
};

