#pragma once

#include "../game_objects/snake.h"
#include "../game_objects/apple.h"
#include "../game_objects/map_factory.h"
#include "../timer/timer.h"
#include "../graphics/graphics_game.h"
#include "../keyboard/keyboard.h"
#include "../graphics/game_point.h"
#include <vector>

class Game
{
	private:
		Snake snake;
		timeMills speed;
		int countApple;
		std::vector<Apple> apples;
		Map* gameMap;
		bool volatile keyPressed;
		GamePoint gamePoints;
	private:
		void createApple();
		void FuncTimer();
	private:
		bool HandleKeyBoard();
		bool cellIsSnake(const Snake& snake, Point<int> x);
		bool crashWall();
		bool isSuicideSnake();
	private:
		int getIdEatApple();
	public:
		Game(NameMap name, timeMills speed, int startLength);
	public:
		void start();
		int getGamePoints();
	public:
		~Game();
};