#pragma once
#include "Exit.h"
#include "start_game_action.h"
#include "../exception/exception.h"

enum ActionName
{
	ExitProgram = 0,
	StartGameSnake = 1
};

class NotCreateAction : public Exception
{
	public:
		NotCreateAction() : Exception("NotCreateAction","this action not exist") {}
};

class ActionFactory
{
	public:
		ActionFactory() = delete;
		ActionFactory(const ActionFactory&) = delete;
	public:
		static Action* createAction(ActionName action) throw (NotCreateAction);

};