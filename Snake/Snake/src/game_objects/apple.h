#pragma once
#include "../graphics/point.h"

class Apple
{
	private:
		Point<int> point;
		int addedLength;
	
	public:
		Apple(Point<int> _point, int _addedLength) : point(_point), addedLength(_addedLength) {}

	public:

		int getAddedLength();
		Point<int>& getPoint();
};