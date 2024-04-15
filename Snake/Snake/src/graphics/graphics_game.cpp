#include "graphics_game.h"

void GraphicsGame::drawSnake(const Snake& snake)
{
	console.setColorText(10);

	std::vector<Point<int>> bodySnake = snake.getBody();

	for (int i = 0; i < bodySnake.size(); i++)
	{
		console.setCursor(bodySnake[i].X, bodySnake[i].Y);
		console << "#";
	}

}

void GraphicsGame::drawMap(const Map& map)
{
	std::vector<std::vector<char>> mapGame = map.getMap();

	for (int i = 0; i < mapGame.size(); i++)
		for (int j = 0; j < mapGame[0].size(); j++)
		{
			console.setCursor(j, i);

			if (mapGame[i][j] == '#')
			{
				console.setColorText(4);
			}
			else
			{
				console.setColorText(0);
			}
				console << mapGame[i][j];
		}

}

void GraphicsGame::drawApple(Apple& apple)
{
	console.setColorText(1);
	console.setCursor(apple.getPoint().X, apple.getPoint().Y);
	console << "$";
}

void GraphicsGame::clearScreen()
{
	console.clear();
}

void GraphicsGame::clearSnake(const Snake& snake)
{
	console.setColorText(0);

	std::vector<Point<int>> bodySnake = snake.getBody();

	for (int i = 0; i < bodySnake.size(); i++)
	{
		console.setCursor(bodySnake[i].X, bodySnake[i].Y);
		console << " ";
	}

}

void GraphicsGame::clearApple(Apple& apple)
{
	console.setColorText(0);
	console.setCursor(apple.getPoint().X, apple.getPoint().Y);
	console << " ";
}

void GraphicsGame::drawGamePoints(GamePoint& gamePoint)
{
	console.setColorText(4);

	console.setCursor(gamePoint.getPoint().X, gamePoint.getPoint().Y);

	std::wstring gamePointText = static_cast<std::wstring>(gamePoint);

	console << gamePointText;

}

void GraphicsGame::clearGamePoints(GamePoint& gamePoint)
{
	console.setColorText(0);

	console.setCursor(gamePoint.getPoint().X, gamePoint.getPoint().Y);

	std::wstring s;
	std::wstring pointText = std::wstring(gamePoint);

	for (int i = 0; i < pointText.length(); i++)
		s += ' ';

	console << s;

}
