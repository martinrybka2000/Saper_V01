#pragma once
class Timer
{
protected:

	sf::Clock clock;
	sf::Time time;

	bool state;
	int HZ;
	
public:

	void Start() { state = true; };
	void Stop() { state = false; };
	
	virtual void Event() = 0;
	virtual void Reset() = 0;

	Timer();
	virtual ~Timer();
};

