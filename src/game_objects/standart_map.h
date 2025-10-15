#pragma once
#include "../exception/range_exception.h"
#include "map.h"

class StandartMap : public Map
{
	private:
		static std::vector<std::vector<char>> map;
		static Direction startDirection;
		static Point<int> startPosition;

	public:
		StandartMap() : Map(map,startDirection,startPosition) {}

	public:
		char getPositionMap(const Point<int>& pos)  const throw (Range) override;
		std::vector<std::vector<char>> getMap() const override;
		Direction getStartDirection() override;
		Point<int> getStartPosition() override;
};