#include <iostream>
#include <thread>
#include <chrono>
#include <conio.h>

#include "menu/menu.h"

using namespace std;


Action* tryCreateAction(ActionName name)
{
	Action* action = nullptr;
	try
	{
		action = ActionFactory::createAction(name);
	}
	catch (NotCreateAction& a)
	{
		action = nullptr;
	}
	return action;
}

int main()
{
	
	int commands = -1;

	do
	{
		Menu::printStartMenu();
		
		wcin >> commands;

		Action* action = tryCreateAction(static_cast<ActionName>(commands));


		if (action != nullptr)
			Menu::executeAction(action);
		else
		{
			console << "there is no such command\n";
			this_thread::sleep_for(static_cast<std::chrono::milliseconds>(300));
			console.clear();
			continue;
		}
		


	} while (true);
	

	return 0;
}