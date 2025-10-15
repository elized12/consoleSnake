#include "game_point.h"

void GamePoint::addPoint(int addedPoint)
{
	point += addedPoint;
}

void GamePoint::erasePoint(int erasePoint)
{
	if (erasePoint <= point)
		point -= erasePoint;
}

int GamePoint::getGamePoint()
{
	return point;
}

Point<int> GamePoint::getPoint()
{
	return positionScreen;
}

GamePoint::operator std::string() const
{
	return std::string(std::to_string(point));
}

GamePoint::operator std::wstring() const
{
	return std::wstring(std::to_wstring(point));
}
