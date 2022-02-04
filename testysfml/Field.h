#pragma once

#include "Displayed.h"
#include "Display.h"
#include "GameContext.h"
#include "Square.h"

class Display;

class Field :
	public Displayed
{
	Display* display;
	GameContext* context;

	vector<vector<Square*>> Squares;
	sf::Texture textures[12];

	stack<sf::Vector2i> list_of_changes;
	sf::Vector2i last_glown;
	bool to_glow;

	sf::RectangleShape rec;

	sf::Vector2i _size;

public:

	void SetDisplay(Display* dis) { display = dis; };

	bool Intersects(sf::Vector2f pos) {
		rec.setOutlineThickness(0);
		sf::FloatRect bounds = rec.getGlobalBounds();
		rec.setOutlineThickness(4);
		return bounds.contains(pos); 
	};

	void UpdateListOfChanges(stack<sf::Vector2i> list, bool glow = false){
		to_glow = glow;
		list_of_changes = list;
	};

	void GlowOff() { 
		if (last_glown.x >= 0 && last_glown.y >= 0)
			Squares[last_glown.x][last_glown.y]->SetTextureColor(sf::Color(210, 210, 210));
		last_glown = sf::Vector2i(-1, -1);
		display->Update();
	};

	void GlowOn(sf::Vector2i pos) {
		if (last_glown != pos){
			Squares[pos.x][pos.y]->SetTextureColor(sf::Color::White);
			if (last_glown.x >= 0 && last_glown.y >= 0)
				Squares[last_glown.x][last_glown.y]->SetTextureColor(sf::Color(210, 210, 210));
			last_glown = pos;
			display->Update();
		}
	};

	void Generate() {};

	virtual void View(sf::RenderWindow* rw);
	virtual void Update();

	Field(sf::Vector2i size, sf::Vector2f position, Display* dis, GameContext* gc);
	~Field();
};

