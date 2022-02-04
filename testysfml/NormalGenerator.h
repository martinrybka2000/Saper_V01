#pragma once
#include "MinesGenerator.h"
class NormalGenerator :
	public MinesGenerator
{
	list<sf::Vector2i> excluded[4];

	int choosen;

	void showexcluded(int x);
	bool checkexisting(sf::Vector2i plus);

	void GenerateNumbers();

public:
	NormalGenerator(int w, int h, int m);
	~NormalGenerator();

	virtual void Generate();
	virtual void Generate(sf::Vector2i v);
	
};

