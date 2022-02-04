#pragma once
#include "Timer.h"
#include "Game.h"
#include "ViewWindow.h"

class NormalTimer :
	public Timer
{
	Game* game;
	ValueWindow* window;

	int time_left;

public:

	virtual void Event();

	virtual void Reset() { 
		time_left = 0; 
		window->SetVal(to_string(time_left));
		window->Update();
	};

	NormalTimer(Game* g, ValueWindow* wind, int hz);
	~NormalTimer();
};

