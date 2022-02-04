#include "stdafx.h"
#include "NormalGenerator.h"

void NormalGenerator::showexcluded(int x)
{
	list<sf::Vector2i>::iterator it;

	for (it = excluded[x].begin(); it != excluded[x].end(); it++)
	{
		sf::Vector2i val = *it;
		cout << "x=" << val.x << " y=" << val.y << endl;
	}
}

bool NormalGenerator::checkexisting(sf::Vector2i pos)
{
	list<sf::Vector2i>::iterator it;

	for (it = excluded[choosen].begin(); it != excluded[choosen].end(); it++)
	{
		if (pos == *it) return false;
	}
	return true;
}

void NormalGenerator::GenerateNumbers()
{
	//************************************   generator liczb w kwadracie bez krawedzi

	for (int i = 1; i < width - 1; i++)      // generuje liczby na obszarze bez krawedzi
	{
		for (int j = 1; j < height - 1; j++)
		{
			if (field[i][j] != -1) {
				int min = 0;
				if (field[i - 1][j] == -1) min++; if (field[i + 1][j] == -1) min++;
				if (field[i][j - 1] == -1) min++; if (field[i][j + 1] == -1) min++;
				if (field[i - 1][j - 1] == -1) min++; if (field[i + 1][j + 1] == -1) min++;
				if (field[i + 1][j - 1] == -1) min++; if (field[i - 1][j + 1] == -1) min++;
				field[i][j] = min;
			}
		}
	}

	//************************************************ generator liczb lewa krawedz

	for (int i = 1; i < height - 1; i++)
	{
		if (field[0][i] != -1) {
			int min = 0;
			if (field[1][i] == -1) min++;
			if (field[0][i - 1] == -1) min++; if (field[0][i + 1] == -1) min++;
			if (field[1][i - 1] == -1) min++; if (field[1][i + 1] == -1) min++;
			field[0][i] = min;
		}
	}

	//************************************************ generator liczb prawa krawedz

	for (int i = 1; i < height - 1; i++)
	{
		if (field[width - 1][i] != -1) {
			int min = 0;
			if (field[width - 2][i] == -1) min++;
			if (field[width - 1][i - 1] == -1) min++; if (field[width - 1][i + 1] == -1) min++;
			if (field[width - 2][i - 1] == -1) min++; if (field[width - 2][i + 1] == -1) min++;
			field[width - 1][i] = min;
		}
	}

	//************************************************ generator liczb gorna krawedz

	for (int i = 1; i < width - 1; i++)
	{
		if (field[i][0] != -1) {
			int min = 0;
			if (field[i][1] == -1) min++;
			if (field[i - 1][0] == -1) min++; if (field[i + 1][0] == -1) min++;
			if (field[i - 1][1] == -1) min++; if (field[i + 1][1] == -1) min++;
			field[i][0] = min;
		}
	}

	//************************************************ generator liczb dolna krawedz

	for (int i = 1; i < width - 1; i++)
	{
		if (field[i][height - 1] != -1) {
			int min = 0;
			if (field[i][height - 2] == -1) min++;
			if (field[i - 1][height - 1] == -1) min++; if (field[i + 1][height - 1] == -1) min++;
			if (field[i - 1][height - 2] == -1) min++; if (field[i + 1][height - 2] == -1) min++;
			field[i][height - 1] = min;
		}
	}

	//************************************************ generator liczb lewy gorny rog

	if (field[0][0] != -1) {
		int min = 0;
		if (field[0][1] == -1) min++;
		if (field[1][0] == -1) min++;
		if (field[1][1] == -1) min++;
		field[0][0] = min;
	}

	//************************************************ generator liczb prawy dolny rog bug

	if (field[width - 1][height - 1] != -1) {
		int min = 0;
		if (field[width - 1][height - 2] == -1) min++;
		if (field[width - 2][height - 1] == -1) min++;
		if (field[width - 2][height - 2] == -1) min++;
		field[width - 1][height - 1] = min;
	}

	//************************************************ generator liczb prawy gorny rog bug

	if (field[0][height - 1] != -1) {
		int min = 0;
		if (field[0][height - 2] == -1) min++;
		if (field[1][height - 1] == -1) min++;
		if (field[1][height - 2] == -1) min++;
		field[0][height - 1] = min;
	}

	//************************************************ generator liczb lewy dolny rog

	if (field[width - 1][0] != -1) {
		int min = 0;
		if (field[width - 1][1] == -1) min++;
		if (field[width - 2][0] == -1) min++;
		if (field[width - 2][1] == -1) min++;
		field[width - 1][0] = min;
	}
}

void NormalGenerator::Generate()
{
	srand(time(NULL));
	int othersmines = mines;

	while (othersmines > 0)               // generuje miny
	{
		for (int i = 0; i < width && othersmines > 0; i++)
		{
			for (int j = 0; j < height && othersmines > 0; j++)
			{
				if (field[i][j] == -1) j++;
				else if ((rand() % 100) <= minesPerCent && checkexisting(sf::Vector2i(i, j))) {
					field[i][j] = -1;
					othersmines -= 1;
				}
			}
		}
	}

	GenerateNumbers();
}

void NormalGenerator::Generate(sf::Vector2i v)
{
	srand(time(NULL));
	int othersmines = mines;

	choosen = rand() % 3;

	list<sf::Vector2i>::iterator it;  // wybranie jednego z 4 obszarów i przesuniecie go o wektor
	for (it = excluded[choosen].begin(); it != excluded[choosen].end(); it++) {
		(*it).x += v.x;
		(*it).y += v.y;
	}
	showexcluded(choosen);

	while (othersmines > 0)               // generuje miny
	{
		for (int i = 0; i < width && othersmines > 0; i++)
		{
			for (int j = 0; j < height && othersmines > 0; j++)
			{
				if (field[i][j] == -1) j++;
				else if ((rand() % 100) <= minesPerCent && checkexisting(sf::Vector2i(i,j))) {
					field[i][j] = -1;
					othersmines -= 1;
				}
			}
		}
	}

	GenerateNumbers();
}

NormalGenerator::NormalGenerator(int w, int h, int m) 
{
	width = w;
	height = h;
	mines = m;
	area = w * h;
	if (mines > (area - 40)) mines = area - 50;
	minesPerCent = 5;
	//minesPerCent = static_cast<int> ( (m*100) / (w*h) );
	

	for (int i = 0; i < width; i++)     // wype³nienie zerami 
	{
		vector<int> row;
		field.push_back(row);
		for (int j = 0; j < height; j++)
		{
			field[i].push_back(0);
		}
	}
//***************Generowanie obszaru wykluczonego z bomb

	for (size_t i = 0; i < 4; i++){
		for (size_t j = 0; j < 3; j++){
			for (size_t k = 0; k < 2; k++){
				excluded[i].push_back(sf::Vector2i(j - 1, k));
			}
		}
	}

	for (size_t i = 0; i < 4; i++) {
		for (size_t j = 0; j < 3; j++) {
			excluded[i].push_back(sf::Vector2i(j - 1, -1));	
		}
	}

	for (size_t i = 1; i < 4; i++) {
		for (size_t j = 0; j < 3; j++) {
			excluded[i].push_back(sf::Vector2i(j - 1, 2));
		}
	}

	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 0; j < 4; j++) {
			excluded[i + 2].push_back(sf::Vector2i(-2, j - 1));
		}
		for (size_t j = 0; j < 4; j++) {
			excluded[i + 2].push_back(sf::Vector2i(2, j - 1));
		}
	}

	for (size_t j = 0; j < 5; j++) {
		excluded[3].push_back(sf::Vector2i(j - 2, 2));
	}

//*************************************************************
	
}


NormalGenerator::~NormalGenerator()
{
}

