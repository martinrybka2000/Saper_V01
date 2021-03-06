// testysfml.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"

#include <Windows.h>


#include "NormalGenerator.h"
#include "Menu.h"
#include "NormalWall.h"
#include "MenuItem.h"
#include "ExitCommand.h"
#include "APP.h"
#include "MoseKeyControler.h"

int main()
{
	//NormalGenerator gen(30, 16, 99);
	//gen.Generate();
	//gen.ShowField();

	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);

	sf::RenderWindow window(sf::VideoMode(800, 600), "Saper");
	window.setFramerateLimit(60);
//	sf::Mouse mouse;

	APP app(&window);
	MoseKeyControler con(&app, &window);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			con.Event(&event);
			if (event.type == sf::Event::Closed)
				window.close();
		}

		app.View(&window);

	}


	return 0;
}

