#pragma once
#include "Command.h"
class NoCommand :
	public Command
{
public:

	virtual void Execute() {};

	NoCommand();
	~NoCommand();
};



NoCommand::NoCommand()
{
}


NoCommand::~NoCommand()
{
}
