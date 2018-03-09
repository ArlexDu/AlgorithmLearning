#include<iostream>
#include <algorithm>
#include <string>
#define LOCAL
using namespace std;

const int MAXN = 100 + 5;
const int MAXC = 60;
string filenames[MAXN];

void printDash() {
	for (int i = 0; i < 60; ++i) {
		cout << "-";
	}
	cout << endl;
}

void printSpace(int n) {
	for (int i = 0; i < n; ++i) {
		cout << " ";
	}
}

int main2() {
#ifdef LOCAL
	freopen("Unix.txt", "r", stdin);
#endif
	int n;
	while (cin >> n) {
		int M = 0;
		for (int i = 0; i < n; ++i) {
			cin >> filenames[i];
			M = max(M, (int)filenames[i].length());
		}
		int cols = (MAXC - M) / (M + 2) + 1;
		int rows = (n - 1) / cols + 1; //向上取整
		printDash();
		sort(filenames, filenames + n);
		for (int r = 0; r < rows; ++r) {
			for (int c = 0; c < cols; ++c) {
				cout << filenames[rows * c + r];
				int length = (int)filenames[rows * c + r].length();
				if (c == cols - 1) {
					printSpace(M - length);
				}
				else {
					printSpace(M - length + 2);
				}
			}
			cout << endl;
		}
	}
	return 0;
}