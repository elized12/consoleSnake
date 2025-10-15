#include "action_factory.h"

Action* ActionFactory::createAction(ActionName actionName)
{
	Action* action = nullptr;

	switch (actionName)
	{
	case ExitProgram:
		action = new Exit();
		break;
	case StartGameSnake:
		action = new StartGame();
		break;
	default:
		throw NotCreateAction();
		break;
	}

	return action;
}
