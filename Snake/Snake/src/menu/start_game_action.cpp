#include "start_game_action.h"

void StartGame::execute()
{
	console.clear();

	console.setColorText(2);

	for (int i = 3; i >= 1; i--)
	{
		console.setCursor(0, 0);
		console << "start in " << i;
		std::this_thread::sleep_for(static_cast<std::chrono::milliseconds>(1000));
	}

	console.clear();

	Game game(nameMap, speedSnake, startLength);
	game.start();

	console.clear();

	console << "GAME OVER";
	std::this_thread::sleep_for(static_cast<std::chrono::milliseconds>(1000));
	
	console.clear();

}
