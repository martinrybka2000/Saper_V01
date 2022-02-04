#pragma once

enum AIState{
	ended,
	flags,
	uncover
};

struct AIdata
{
	enum AIState state;
	
	stack<sf::Vector2i> flags_changes;
	stack<sf::Vector2i> uncover_changes;
};