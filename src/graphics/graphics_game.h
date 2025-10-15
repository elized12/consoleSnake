#pragma once

#include "../game_objects/snake.h"
#include "../game_objects/apple.h"
#include "../game_objects/standart_map.h"
#include "../console/console.h"
#include "game_point.h"
class GraphicsGame
{
	private:
		GraphicsGame() = delete;
	public:
		static void drawSnake(const Snake& snake);
		static void drawMap(const Map& map);
		static void drawApple(Apple& apple);
		static void clearScreen();
		static void clearSnake(const Snake& snake);
		static void clearApple(Apple& apple);
		static void drawGamePoints(GamePoint& gamePoint);
		static void clearGamePoints(GamePoint& gamePoint);
};