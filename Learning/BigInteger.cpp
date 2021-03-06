#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct BigInteger {
	static const int BASE = 10000000;
	static const int WIDTH = 8;
	vector<int> s;

	BigInteger(long long num = 0) {
		*this = num;
	}

	BigInteger operator = (long long num) {
		s.clear();
		do {
			s.push_back(num%BASE);
			num /= BASE;
		} while (num > 0);
		return *this;
	}

	BigInteger operator =(const string& str) {
		s.clear();
		int x, len = (str.length() - 1) / WIDTH + 1;
		for (int i = 0; i < len; i++) {
			int end = str.length() - i*WIDTH;
			int start = max(0,end - WIDTH);
			sscanf_s(str.substr(start, end).c_str(), "%d", &x);
			s.push_back(x);
		}
		return *this;
	}
};

int main() {
	string s = "abcdefg";
	int num = s.length();
	return 0;
}