#pragma once
template<typename T>
class Point
{
public:
	Point(T x =0,T y=0);
	~Point();
	Point operator + (const Point& A);
	T x, y;
};

