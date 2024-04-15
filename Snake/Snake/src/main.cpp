#include <iostream>
#include <thread>
#include <chrono>
#include <conio.h>

#include "logic/game.h"

using namespace std;


void f()
{

}

int main()
{
	
	Game game(StMap, 500, 3);

	game.start();


	return 0;
}