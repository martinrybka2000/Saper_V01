#pragma once

#include "Controllable.h"
#include "Field.h"
#include "GameContext.h"
#include "Display.h"
#include "ValueWindow.h"

enum State { started, stoped, nogame, over, win };

class Gamealgorithm:
	public Controllable
{
	vector<vector<int>> algorithmcontext;
	stack<sf::Vector2i> changes;

	GameContext *gamecontext;
	Field* field;
	ValueWindow* window;
	sf::RenderWindow* renderwindow;

	sf::Vector2i last_updated;
	sf::Vector2f field_position;
	sf::Vector2i context_size;

	int left_mines;
	int const_left_mines;

	enum State state;

	bool Uncoverempty(int x, int y);
	void Update_mines(){
		if (left_mines >= 0) window->SetVal(to_string(left_mines));
	};

	void GameOver();
	void GameWin();

	void ClearStack() {
		while (!changes.empty()) changes.pop();
	}

public:

	virtual void Upgrade(sf::Vector2i v);
	virtual void Upgrade(sf::Keyboard::Key k) {};
	virtual void Upgrade(sf::Mouse::Wheel wh) {};
	virtual void Click(sf::Vector2i v, sf::Mouse::Button button);

	void SetField(Field* f) { field = f; };
	void SetContext(vector<vector<int>> context) {
		algorithmcontext = context;

		for (int i = 0; i < context_size.x; i++) { // bug odwrocone x y 
			for (int j = 0; j < context_size.y; j++) {
				if (algorithmcontext[i][j] == -1) left_mines++;
			}
		}
		const_left_mines = left_mines;

		window->SetVal(to_string(left_mines));
		window->Update();
	}

	sf::RenderWindow* CreateRenderWindow() {
		if (renderwindow) {
			renderwindow->create(sf::VideoMode((square_size * context_size.x) + (4 * square_size), (square_size * context_size.y) + (5 * square_size)), "Saper");
			return renderwindow;
		}
		else return new sf::RenderWindow(sf::VideoMode((square_size * context_size.x) + (4 * square_size), (square_size * context_size.y) + (5 * square_size)), "Saper");;
	};
	enum State CheckRules() { return state; };
	sf::Vector2i ChceckActiveSquare(sf::Vector2i mouse_pos);

	Gamealgorithm(Display* dis, ValueWindow* wind, vector<vector<int>> context);
	Gamealgorithm(Display* dis, ValueWindow* wind, sf::Vector2i fieldsize);
	~Gamealgorithm();
};

