#include "stdafx.h"
#include "Gamealgorithm.h"
#include "NormalContext.h"

void Gamealgorithm::GameOver() {

	for (int i = 0; i < context_size.x; i++) {
		for (int j = 0; j < context_size.y; j++) {
			if (algorithmcontext[i][j] == -1) {
				static_cast<NormalContext*> (gamecontext)->SetContext(sf::Vector2i(i, j), mine);
				changes.push(sf::Vector2i(i, j));
			}
		}
	}
	field->UpdateListOfChanges(changes);

	ClearStack();

	state = over;
}

void Gamealgorithm::GameWin() {

	int cnt = gamecontext->GetCovered();

	if (const_left_mines >= cnt) {
		bool end = true;
		cnt = context_size.x * context_size.y;

		for (int i = 0; i < context_size.x; i++) {
			for (int j = 0; j < context_size.y; j++) {
				if (gamecontext->GetContext(i, j) != covered && gamecontext->GetContext(i, j) != flag) {
					cnt--;
				}
			}
		}
		for (int i = 0; i < context_size.x; i++) {
			for (int j = 0; j < context_size.y; j++) {
				if (gamecontext->GetContext(i, j) == covered || gamecontext->GetContext(i, j) == flag) {
					if (algorithmcontext[i][j] == -1) cnt--;
				}
			}
		}

		if (cnt == 0 && end) state = win;
	}
}

bool Gamealgorithm::Uncoverempty(int x, int y)
{
	if (x >= context_size.x || x < 0 || y >= context_size.y || y < 0) return 0;

	InsideFieled insidefield = gamecontext->GetContext(x, y);
	int contextvalue = algorithmcontext[x][y];

	if (contextvalue == -1) return 0;
	else if (insidefield == flag) return 0;
	else if (insidefield == InsideFieled::empty) return 0;
	else if (insidefield != covered && contextvalue != 0) return 0;

	else if (insidefield == covered && contextvalue != 0) {
		static_cast<NormalContext*> (gamecontext)->SetContext(sf::Vector2i(x,y), static_cast<InsideFieled> (contextvalue));
		changes.push(sf::Vector2i(x, y));
		return 0;
	}

	else {
		static_cast<NormalContext*> (gamecontext)->SetContext(sf::Vector2i(x, y), InsideFieled::empty);
		changes.push(sf::Vector2i(x, y));

		Uncoverempty(x + 0, y + 1);
		Uncoverempty(x + 0, y - 1);
		Uncoverempty(x + 1, y + 0);
		Uncoverempty(x - 1, y + 0);
		Uncoverempty(x + 1, y + 1);
		Uncoverempty(x + 1, y - 1);
		Uncoverempty(x - 1, y + 1);
		Uncoverempty(x - 1, y - 1);
		return 0;
	}
}

void Gamealgorithm::Click(sf::Vector2i v, sf::Mouse::Button button)
{
	if (field->Intersects(sf::Vector2f(static_cast<float> (v.x), static_cast<float> (v.y)))) {

		v.x -= static_cast<int> (field_position.x);
		v.y -= static_cast<int> (field_position.y);

		sf::Vector2i pos;
		pos.x = static_cast<int> (v.x / square_size);
		pos.y = static_cast<int> (v.y / square_size);


		if (button == sf::Mouse::Right) {
			if (gamecontext->GetContext(pos.x, pos.y) == flag) {
				static_cast<NormalContext*> (gamecontext)->SetContext(pos, covered);
				left_mines++;
				Update_mines();
			}
			else if (gamecontext->GetContext(pos.x, pos.y) == covered) {
				static_cast<NormalContext*> (gamecontext)->SetContext(pos, flag);
				left_mines--;
				Update_mines();
			}
			changes.push(pos);
			field->UpdateListOfChanges(changes);
			changes.pop();
		}

		else if (button == sf::Mouse::Left) {

			if (gamecontext->GetContext(pos.x, pos.y) != flag) {

				if (algorithmcontext[pos.x][pos.y] == -1) GameOver();

				else {

					if (algorithmcontext[pos.x][pos.y] == 0) {
						Uncoverempty(pos.x, pos.y);
						field->UpdateListOfChanges(changes);
						ClearStack();
					}

					else{
						static_cast<NormalContext*> (gamecontext)->SetContext(pos,static_cast<InsideFieled> (algorithmcontext[pos.x][pos.y]));
						changes.push(pos);
						field->UpdateListOfChanges(changes);
						changes.pop();
					}
					GameWin();
				}		
			}
		}

		field->Update();
	}
}

void Gamealgorithm::Upgrade(sf::Vector2i v)
{
	if (field->Intersects(sf::Vector2f(static_cast<float> (v.x), static_cast<float> (v.y)))) {
		v.x -= static_cast<int> (field_position.x);
		v.y -= static_cast<int> (field_position.y);

		sf::Vector2i pos;
		pos.x = static_cast<int> (v.x / square_size);
		pos.y = static_cast<int> (v.y / square_size);

		if (gamecontext->GetContext(pos.x, pos.y) == covered || gamecontext->GetContext(pos.x, pos.y) == flag) 
			field->GlowOn(pos);

		else field->GlowOff();
	}
	else field->GlowOff();
}

sf::Vector2i Gamealgorithm::ChceckActiveSquare(sf::Vector2i mouse_pos)
{
	if (field->Intersects(sf::Vector2f(static_cast<float> (mouse_pos.x), static_cast<float> (mouse_pos.y)))) {
		mouse_pos.x -= static_cast<int> (field_position.x);
		mouse_pos.y -= static_cast<int> (field_position.y);

		sf::Vector2i pos;
		pos.x = static_cast<int> (mouse_pos.x / square_size);
		pos.y = static_cast<int> (mouse_pos.y / square_size);

		return pos;
	}
	else return sf::Vector2i(-1, -1);
}


Gamealgorithm::Gamealgorithm(Display* dis, ValueWindow* wind, vector<vector<int>> context)
{
	window = wind;
	algorithmcontext = context;
	state = started;

	context_size.x = context.size();
	context_size.y = context[0].size();

	for (int i = 0; i < context_size.x; i++){
		for (int j = 0; j < context_size.y; j++){
			if (algorithmcontext[i][j] == -1) left_mines++;
		}
	}
	const_left_mines = left_mines;

	field_position.x = square_size * 2;
	field_position.y = square_size * 2;

	gamecontext = new NormalContext(context_size.x, context_size.y);

	renderwindow = new sf::RenderWindow(sf::VideoMode((square_size * context_size.x) + (4 * square_size), (square_size * context_size.y) + (5 * square_size)), "Saper");

	window->SetSize(sf::Vector2f(square_size * 2, square_size));
	window->SetVal(to_string(left_mines));
	window->SetColor(sf::Color(220, 220, 220));

	field = new Field(context_size, field_position, dis, gamecontext);

	dis->AttachDisplayed(field);

	field->Update();
}

Gamealgorithm::Gamealgorithm(Display* dis, ValueWindow* wind, sf::Vector2i fieldsize)
{
	window = wind;
	state = started;

	context_size = fieldsize;
	
	field_position.x = square_size * 2;
	field_position.y = square_size * 2;

	window->SetSize(sf::Vector2f(square_size * 2, square_size));
	window->SetVal(to_string(left_mines));
	window->SetColor(sf::Color(220, 220, 220));

	gamecontext = new NormalContext(context_size.x, context_size.y);
	renderwindow = new sf::RenderWindow(sf::VideoMode((square_size * context_size.x) + (4 * square_size), (square_size * context_size.y) + (5 * square_size)), "Saper");

	field = new Field(context_size, field_position, dis, gamecontext);

	dis->AttachDisplayed(field);

	field->Update();
}


Gamealgorithm::~Gamealgorithm()
{
	if (field) delete field;
	delete gamecontext;
}
