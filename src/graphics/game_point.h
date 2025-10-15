#pragma once
#include <string>
#include "point.h"

class GamePoint
{
	private:
		int point;
		Point<int> positionScreen;
	public:
		GamePoint(int startPoint, Point<int> _positionScreen) : point(startPoint), positionScreen(_positionScreen ) {}
	public:
		void addPoint(int addedPoint);
		void erasePoint(int erasePoint);
	public:
		int getGamePoint();
	public:
		Point<int> getPoint();
	public:
		operator std::string() const;
		operator std::wstring() const;
};
