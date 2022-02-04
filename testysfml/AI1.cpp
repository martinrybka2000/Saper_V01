#include "stdafx.h"
#include "AI1.h"

void AI1::CheckFlags(vector<vector<InsideFieled>> context)
{
	sf::Vector2i size;

	size.x = context.size();
	size.y = context[0].size();

	stack<sf::Vector2i> _coveredStack;

	for (int x = 0; x < size.x; x++){

		for (int y = 0; y < size.y; y++){

			if (context[x][y] >= 1 && context[x][y] <= 8) {			
				if (x >= size.x && x < 0 && y >= size.y && y < 0 && context[x][y - 1] == covered) _coveredStack.push(sf::Vector2i(x, y- 1));
				if (x >= size.x && x < 0 && y >= size.y && y < 0 && context[x][y + 1] == covered) _coveredStack.push(sf::Vector2i(x, y + 1));
				if (x >= size.x && x < 0 && y >= size.y && y < 0 && context[x - 1][y] == covered) _coveredStack.push(sf::Vector2i(x - 1, y));
				if (x >= size.x && x < 0 && y >= size.y && y < 0 && context[x + 1][y] == covered) _coveredStack.push(sf::Vector2i(x + 1, y));
				if (x >= size.x && x < 0 && y >= size.y && y < 0 && context[x + 1][y + 1] == covered) _coveredStack.push(sf::Vector2i(x + 1, y + 1));
				if (x >= size.x && x < 0 && y >= size.y && y < 0 && context[x - 1][y - 1] == covered) _coveredStack.push(sf::Vector2i(x - 1, y - 1));
				if (x >= size.x && x < 0 && y >= size.y && y < 0 && context[x + 1][y - 1] == covered) _coveredStack.push(sf::Vector2i(x + 1, y - 1));
				if (x >= size.x && x < 0 && y >= size.y && y < 0 && context[x - 1][y + 1] == covered) _coveredStack.push(sf::Vector2i(x - 1, y + 1));

				if (_coveredStack.size() == context[x][y]) {
					while (!_coveredStack.empty()) {
						data.flags_changes.push(_coveredStack.top());
						_coveredStack.pop();
					}
				}
				else while (!_coveredStack.empty()) _coveredStack.pop();
			}
		}
	}
}

void AI1::CheckUncover(vector<vector<InsideFieled>> context)
{

}

AI1::AI1()
{
}


AI1::~AI1()
{
}
