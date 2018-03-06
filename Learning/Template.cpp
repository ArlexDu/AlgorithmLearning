#include <iostream>
#include <string>
#include <sstream>
#include "Point.h"
using namespace std;

template<typename T>
ostream& operator << (ostream &out,Point<T>& p) {
	out << "(" << p.x << "," << p.y << ")";
	return out;
}

template<typename T>
T sum(T* begin, T* end) {
	T* p = begin;
	T ans = 0;
	for (T* p = begin; p != end; p++) {
		ans = ans + *p;
	}
	return ans;
}

int main() {
	Point<int> a,b(1,2);
	a.x = 3;
	cout << a + b << endl;
	int i[] = { 1,2,3,4,5 };
	cout << sum(i, i + 4) << endl;
	Point<double> p[] = { Point<double>(1.1,2.2),Point<double>(3.3,4.4),Point<double>(5.5,6.6),Point<double>(7.7,8.8) };
	cout << sum(p, p + 4) << endl;
	system("pause");
	return 0;
}