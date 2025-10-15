#pragma once


template<class T>
class Point
{
	public:
		T Y, X;
	public:
		Point(T x = 0, T y = 0) : X(x), Y(y) {}
	public:
		bool operator==(const Point& p);
		bool operator!=(const Point& p);

};

template<class T>
inline bool Point<T>::operator==(const Point& p)
{
	return Y == p.Y && X == p.X;
}

template<class T>
inline bool Point<T>::operator!=(const Point& p)
{
	return !(this->operator==(p));
}
