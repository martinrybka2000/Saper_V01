#pragma once
#include "AIdata.h"
#include "GameContext.h"

class AbstractAI
{
protected:

	AIdata data;

	void AdFalg(sf::Vector2i pos) { data.flags_changes.push(pos); };
	void AdUncover(sf::Vector2i pos) { data.uncover_changes.push(pos); };

	virtual void CheckFlags(vector<vector<InsideFieled>> context) = 0;
	virtual void CheckUncover(vector<vector<InsideFieled>> context) = 0;

public:

	AIdata& TemplateMethod(vector<vector<InsideFieled>> context);

	AbstractAI();
	virtual ~AbstractAI();
};

