#include "stdafx.h"
#include "NormalContext.h"

//void NormalContext::SetContext(sf::Vector2i position, enum InsideFieled value)
//{
//	ContextField[position.x][position.y] = value;
//}

NormalContext::NormalContext(int x, int y)
{
	size.x = x;
	size.y = y;

	for (int i = 0; i < x; i++)     // wype³nienie zakrytym
	{
		vector<InsideFieled> row;
		ContextField.push_back(row);
		for (int j = 0; j < y; j++){
			ContextField[i].push_back(covered);
			_covered++;
		}
	}
}


NormalContext::~NormalContext()
{
}
