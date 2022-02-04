#include "stdafx.h"
#include "NormalTimer.h"

void NormalTimer::Event()
{
	if (state && clock.getElapsedTime() >= time) {

		time_left++;
		clock.restart();

		window->SetVal(to_string(time_left));
		window->Update();
	}
}


NormalTimer::NormalTimer(Game* g, ValueWindow* wind, int hz): time_left(0)
{
	game = g;
	window = wind;
	HZ = hz;

	time = sf::seconds(static_cast<float>(1/hz));
}


NormalTimer::~NormalTimer()
{
}
