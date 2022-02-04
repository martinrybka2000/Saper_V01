#include "stdafx.h"
#include "MinesGenerator.h"

void MinesGenerator::ShowField()
{
	stringstream view;

	view << "**************Pole***************" << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (field[i][j] == -1) view << "*" << " ";
			else view << field[i][j] << " ";
		}
		view << endl;
	}

	view << "*********************************" << endl << endl;

	cout << view.str();


	system("pause");
	//return sf::Vector2i(width, height);
}

MinesGenerator::MinesGenerator()
{
}


MinesGenerator::~MinesGenerator()
{

}
