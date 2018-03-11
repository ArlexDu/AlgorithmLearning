#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//#define LOCAL

const int max_col = 60;

void print(string& s,int number){
    cout << s;
    for(int i=number;i>=s.length();i--)
        cout<<" ";
}


int main() {
#ifdef LOCAL
	//好
	freopen("/Users/arlex/Documents/Project/C:C++/AlgorithmLearning/Learning/Unix.txt", "r", stdin);
	//坏
//	freopen("/Users/arlex/Documents/Project/C:C++/AlgorithmLearning/Learning/Unix.txt", "r", stdin);
#endif
    int n;
    while (cin >> n) {
        int max_filename = 0;
        vector<string> list;
        list.clear();
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
		int rows = (n-1) / cols + 1;

//        cout<<"cols "<<cols<<endl;
//        cout<<"rows "<<rows<<endl;

		for (int i = 0; i < max_col; i++)
			cout << "-";
		cout << endl;

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (i + rows*j >= n) {
					break;
				}
				int num = i + rows*j;
                int number = (j == cols-1)?max_filename:(max_filename+2);
                print(list[num],number);
			}
            cout << endl;
		}
	}
#ifdef  LOCAL
	fclose(stdin);
#endif //  LOCAL
	return 0;

}