#include "stdafx.h"
#include "Field.h"

//void Field::UpdateListOfChanges(stack<sf::Vector2i> list, bool glow)
//{ 
//	to_glow = glow;
//	list_of_changes = list; 
//};

void Field::View(sf::RenderWindow* rw)
{
	rw->draw(rec);

	for (int i = 0; i < _size.x; i++)
	{
		for (int j = 0; j < _size.y; j++)
		{
			Squares[i][j]->View(rw);
		}
	}
}

void Field::Update()
{
	if (!list_of_changes.empty()) {

		while (!list_of_changes.empty())
		{
			sf::Vector2i pos = list_of_changes.top();
			Squares[pos.x][pos.y]->SetTexture(&textures[context->GetContext(pos.x, pos.y) + 2]);
			list_of_changes.pop();
		}

		display->Update();
	}
}

Field::Field(sf::Vector2i size, sf::Vector2f position, Display* dis, GameContext* gc)
{
	display = dis;
	_size = size;
	context = gc;

	rec.setSize(sf::Vector2f(square_size * size.x, square_size * size.y));
	rec.setPosition(position);
	rec.setOutlineThickness(4);
	rec.setOutlineColor(sf::Color::Black);

	string filename("textures/texture_");

	for (int i = 0; i < 12; i++){
		textures[i].loadFromFile(filename + to_string(i) + ".png");
	}

	sf::FloatRect bounds = rec.getGlobalBounds();
	bounds.top += rec.getOutlineThickness();
	bounds.left += rec.getOutlineThickness();
	for (int i = 0; i < _size.x; i++){
		vector<Square*> row;
		Squares.push_back(row);
		for (int j = 0; j < size.y; j++){
			
			sf::Vector2f pos(bounds.left + (i * square_size), bounds.top + (j * square_size) );
			Squares[i].push_back(new Square(pos, &textures[InsideFieled::covered + 2], sf::Color(210, 210, 210) ));
		}
	}

	last_glown = sf::Vector2i(-1,-1);
	to_glow = false;
}

Field::~Field()
{
	vector<vector<Square*>>::iterator it;
	vector<Square*>::iterator it2;

	for (it = Squares.begin(); it != Squares.end(); it++){
		for  (it2 = it->begin(); it2 != it->end(); it2++){
			delete *it2;
		}
	}
}
