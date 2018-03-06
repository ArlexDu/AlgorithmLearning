#include "Point.h"

template<typename T>
Point<T>::Point(T x, T y):x(x),y(y)
{
}

template<typename T>
Point<T>::~Point()
{
}

template<typename T>
Point Point<T>::operator + (const Point<T>& p) {
	return Point(this->x + p.x, this->y + p.y);
}
