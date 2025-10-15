#pragma once
#include "action_factory.h"
#include "../console/console.h"

class Menu
{
	public:
		Menu() = delete;
	public:
		static void printStartMenu();
		static void executeAction(Action* action);
};