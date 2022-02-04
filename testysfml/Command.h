#pragma once
class Command
{
protected:
	Command();

public:
	virtual ~Command();

	virtual void Execute() = 0;
};

