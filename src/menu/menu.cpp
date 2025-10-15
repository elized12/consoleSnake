#include "menu.h"

void Menu::printStartMenu()
{
	console.setColorText(2);
	console.clear();
	console <<  L"1.StartGame\n";
	console << L"0.Exit\n";
	console << L"select item\n";
}

void Menu::executeAction(Action* action)
{
	action->execute();
}
