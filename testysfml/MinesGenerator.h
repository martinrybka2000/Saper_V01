#pragma once


class MinesGenerator
{
protected:

	int width;
	int height;
	int mines;
	int area;
	int minesPerCent;

	vector<vector<int>> field;

	MinesGenerator();

public:

	vector<vector<int>> GetField() { return field; };

	sf::Vector2i GetSize() { return sf::Vector2i(width, height); };

	void ShowField();

	virtual void Generate() = 0;
	virtual void Generate(sf::Vector2i v) = 0;

	virtual ~MinesGenerator();

};




