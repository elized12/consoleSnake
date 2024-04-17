#include "game.h"
#include <functional>
#include <mutex>
#include <thread>
#include <chrono>


std::mutex moveMutex;

bool Game::cellIsSnake(const Snake& snake, Point<int> point)
{
	std::vector<Point<int>> bodySnake = snake.getBody();

	for (int i = 0; i < bodySnake.size(); i++)
		if (bodySnake[i] == point)
			return true;

	return false;
}

void Game::createApple()
{
	int x, y;

	std::vector<std::vector<char>> arrMap = gameMap->getMap();

	x = rand() % arrMap[0].size();
	y = rand() % arrMap.size();

	while (arrMap[y][x] == '#' || cellIsSnake(snake,Point<int>(x,y)))
	{
		x = rand() % arrMap[0].size();
		y = rand() % arrMap.size();
	}

	apples.push_back(Apple(Point<int>(x, y), 1));


}

void Game::FuncTimer()
{
	GraphicsGame::clearSnake(snake);
	
	moveMutex.lock();
	
	snake.move();

	moveMutex.unlock();

	GraphicsGame::drawSnake(snake);

	for (int i = 0; i < apples.size(); i++)
		GraphicsGame::drawApple(apples[i]);

	GraphicsGame::clearGamePoints(gamePoints);
	GraphicsGame::drawGamePoints(gamePoints);

}

bool Game::HandleKeyBoard()
{
	
		if (KeyBoard::isPressedKey())
		{
			switch (KeyBoard::getKeyPressed())
			{
			case KeyCode::ArrowDown:
			{
				if (snake.getProhibitedDirection() != Direction::DOWN)
						snake.setDirection(Direction::DOWN);

					break;
				}
				case KeyCode::ArrowUP:
				{
					if (snake.getProhibitedDirection() != Direction::UP)
						snake.setDirection(Direction::UP);

					break;
				}
				case KeyCode::ArrowLeft:
				{
					if (snake.getProhibitedDirection() != Direction::LEFT)
						snake.setDirection(Direction::LEFT);

					break;
				}
				case KeyCode::ArrowRight:
				{
					if (snake.getProhibitedDirection() != Direction::RIGHT)
						snake.setDirection(Direction::RIGHT);

					break;
				}

				case KeyCode::Esc:
				{
					return false;
					break;
				}


				default:
					break;
				}

			return true;
		}
		return true;
}

int Game::getIdEatApple()
{
	Point<int> headSnake = snake.getHead();

	for (int i = 0; i < apples.size(); i++)
		if (headSnake == apples[i].getPoint())
		{	
			return i;
		}

	return -1;
}

bool Game::crashWall()
{
	Point<int> headCoordinate = snake.getHead();

	if (gameMap->getPositionMap(headCoordinate) == '#' ||
		isSuicideSnake())
	{
		return true;
	}
	return false;
}

bool Game::isSuicideSnake()
{
	std::vector<Point<int>> bodySnake = snake.getBody();
	Point<int> headSnake = bodySnake[0];

	for (int i = 1; i < bodySnake.size(); i++)
		if (headSnake == bodySnake[i])
			return true;

	return false;

	
}

Game::Game(NameMap name, timeMills speed, int startLength) : snake(UP, 3, Point<int>(2, 3)) , gamePoints(0,Point<int>(24,0))
{
	srand(time(NULL));

	gameMap = MapFactory::CreateMap(name);

	this->speed = speed;

	std::vector<Point<int>> points;

	points.push_back(gameMap->getStartPosition());

	switch (gameMap->getStartDirection())
	{
	case Direction::UP:
		for (int i = 1; i < startLength; i++)
			points.push_back(Point<int>(
				gameMap->getStartPosition().X, gameMap->getStartPosition().Y + i
			));
		break;

	case Direction::DOWN:
		for (int i = 1; i < startLength; i++)
			points.push_back(Point<int>(
				gameMap->getStartPosition().X, gameMap->getStartPosition().Y - i
			));
		break;

	case Direction::LEFT:
		for (int i = 1; i < startLength; i++)
			points.push_back(Point<int>(
				gameMap->getStartPosition().X + i, gameMap->getStartPosition().Y
			));
		break;

	case Direction::RIGHT:
		for (int i = 1; i < startLength; i++)
			points.push_back(Point<int>(
				gameMap->getStartPosition().X - i, gameMap->getStartPosition().Y
			));
		break;

	default:
		break;
	}

	snake = Snake(gameMap->getStartDirection(), points);

	

}

void Game::start()
{
	Timer timer(speed);

	console.setCursorVisible(false);

	timer.addEvent([this] {FuncTimer(); });

	GraphicsGame::clearScreen();

	GraphicsGame::drawMap(*gameMap);

	GraphicsGame::drawGamePoints(gamePoints);

	createApple();

	for (int i = 0; i < apples.size(); i++)
		GraphicsGame::drawApple(apples[i]);


	timer.start();

	while (true)
	{

		if (!HandleKeyBoard())
		{
			timer.stop();
			break;
		}
		
		moveMutex.lock();

		if (crashWall())
		{
			timer.stop();
			moveMutex.unlock();
			break;
		}
		moveMutex.unlock();

		int idApple = getIdEatApple();

		if (idApple != -1)
		{
			
			apples.erase(apples.begin() + idApple);
			
			snake.addLength(1);
			gamePoints.addPoint(100);
			createApple();
		}
		
	}

}

int Game::getGamePoints()
{
	return gamePoints.getGamePoint();
}

Game::~Game() 
{
	delete gameMap;
}
