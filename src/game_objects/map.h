#pragma once
#include <vector>
#include "snake.h"

class Map
{



	protected:
		std::vector<std::vector<char>> map;
		Direction startDirection;
		Point<int> startPosition;

		Map(std::vector<std::vector<char>>& _map,Direction stDirection, Point<int> stPos) : map(_map), startDirection(stDirection), startPosition(stPos) {}

	public:
		
		int getWidth() const;
		int getHeight() const;

	public:
		virtual char getPositionMap(const Point<int>& pos) const = 0;
		virtual std::vector<std::vector<char>> getMap() const = 0;
		virtual Direction getStartDirection() = 0;
		virtual Point<int> getStartPosition() = 0;

};