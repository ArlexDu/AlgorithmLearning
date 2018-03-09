#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define LOCAL

const int max_col = 60;

int main() {
	int n;
	int max_filename = 0;
	vector<string> list;
#ifdef LOCAL
	//好
	freopen("Unix.txt", "r", stdin);
	//坏
	//freopen("‪Unix.txt", "r", stdin);
#endif
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			string filename;
			cin >> filename;
			if (filename.length() > max_filename)
				max_filename = filename.length();
			list.push_back(filename);
		}
		//由小到大排序
		sort(list.begin(), list.end());
		//计算一共有多少列
		int cols = (max_col - max_filename) / (max_filename + 2) + 1;
		int rows = n / cols + 1;

		for (int i = 0; i < max_col; i++)
			cout << "-";
		cout << endl;

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (i + rows*j >= n) {
					cout << endl;
					break;
				}
				int num = i + rows*j;
				cout << list[num] << "  ";
			}
		}
	}
#ifdef  LOCAL
	fclose(stdin);
#endif //  LOCAL
	return 0;

}