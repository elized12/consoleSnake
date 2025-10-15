#pragma once
#include <vector>
#include "../graphics/point.h"
#include <cstdarg>

enum Direction
{
	UP = 0,
	LEFT = 1,
	DOWN = 2,
	RIGHT = 3
};




class Snake
{
	private:
		std::vector<Point<int>> body;
		size_t length;
		Direction direction;
		size_t addedLength;
		
	private:
		int head() const;
		int tail() const;
		void moveNoHead();

	public:

		Snake(Direction startDireciton, int length, ...);
		Snake(Direction startDirection, std::vector<Point<int>> body);

	public:

		size_t getLength() const;

		Direction getDirection() const;
		Direction getProhibitedDirection();

		std::vector<Point<int>> getBody() const;

		void setDirection(Direction direction);
		void move();
		void addLength(int addSize);
		void RemoveLength(int removeSize);

		Point<int> getHead();

		
};