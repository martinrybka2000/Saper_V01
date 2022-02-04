#include "stdafx.h"
#include "Game.h"
#include "NormalTimer.h"
#include "MoseKeyControler.h"


void Game::Event(sf::RenderWindow* rw) {

	sf::Vector2u winsize = rw->getSize();

	while (rw->isOpen())
	{
		sf::Event event;
		while (rw->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				rw->close();
			if (event.type == sf::Event::Resized)
				rw->setSize(winsize);
			if (state == nogame && event.type == sf::Event::MouseButtonReleased) {
 				minesgenerator->Generate(gamealgorithm->ChceckActiveSquare(static_cast<MoseKeyControler*>(controler)->GetMousePos()));
				gamealgorithm->SetContext(minesgenerator->GetField());
				//static_cast<MoseKeyControler*>(controler)->SetContext(minesgenerator->GetField());
				timer->Start();
				state = started;
			}
		}
		if (state == started)
		{
			timer->Event();
			controler->Event(&event);
			state = gamealgorithm->CheckRules();
		}	
		else if (state == over || state == win) {
			ValueWindow* win = new ValueWindow(display, windowStr[state - 3]);
			positioncalculator->AddObject(win, sf::Vector2f(0, 30), PositionCalculator::centre_up);
			positioncalculator->UpdatePositions();
			display->AttachDisplayed(win);
			display->Update();
			state = stoped;
		}
	}

};

void Game::NewGame()
{
	display->DeleteDisplayed();
	display->AttachDisplayed(windows[0]);
	display->AttachDisplayed(windows[1]);
	
	if (controler) delete controler;
	if (positioncalculator) delete positioncalculator;
	if (gamealgorithm) delete gamealgorithm;

	minesgenerator = gamebuilder->BuildAlgorythm();

	gamealgorithm = new Gamealgorithm(display, static_cast<ValueWindow*> (windows[1]), minesgenerator->GetSize());
	renderwindow = gamealgorithm->CreateRenderWindow();

	controler = new MoseKeyControler(gamealgorithm, renderwindow);
	//controler = new AIControler(gamealgorithm, renderwindow);

	positioncalculator = new PositionCalculator(renderwindow);

	positioncalculator->AddObject(windows[0], sf::Vector2f(50,30), PositionCalculator::left_down);
	positioncalculator->AddObject(windows[1], sf::Vector2f(50,30), PositionCalculator::right_down);
	positioncalculator->UpdatePositions();

	display->SetRenderWindow(renderwindow);
	display->Update();

	state = nogame;
	timer->Reset();

	Event(renderwindow);

	timer->Stop();
	state = stoped;
}

void Game::Resume()
{
	if (state == stoped || state == over || state == win) {

		renderwindow = gamealgorithm->CreateRenderWindow();
		
		state = started;
		timer->Start();

		Event(renderwindow);

		timer->Stop();
		state = stoped;
	}
}

Game::Game(GameBuilder* gb)
{
	gamebuilder = gb;
	display = new Display();

	windows[0] = new PictureDecorator(new ValueWindow(display, "0"), 10 ,"textures/clock.png");
	windows[0]->SetSize(sf::Vector2f(square_size * 2, square_size));
	windows[0]->SetVal(to_string(0));
	windows[0]->SetColor(sf::Color(220, 220, 220));

	windows[1] = new PictureDecorator( new ValueWindow(display, "0"), 10 ,"textures/bomb.png" );
	display->AttachDisplayed(windows[0]);
	display->AttachDisplayed(windows[1]);

	timer = new NormalTimer(this, static_cast<ValueWindow*> (windows[0]), 1);

	state = nogame;

	windowStr[0] = "HA HA ";
	windowStr[1] = "CONGRATULATION";
}


Game::~Game()
{
	delete minesgenerator;
	delete display;
	delete timer;
	if (gamealgorithm) delete gamealgorithm;
	if (controler) delete controler;
	if (positioncalculator) delete positioncalculator;
}
