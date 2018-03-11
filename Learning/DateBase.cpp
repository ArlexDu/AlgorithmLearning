#include <iostream>
#include <map>
#include <cstring>
//#define LOCAL
using namespace std;
const int max_row = 10005;
const int max_col = 15;
string data[max_row][max_col];
map<string,int> dic;
typedef pair<int,int> two;
map<two,int> com;

int main(){
#ifdef LOCAL
    freopen("/Users/arlex/Documents/Project/C:C++/AlgorithmLearning/Learning/DataBase.txt","r",stdin);
#endif
    int n,m;
    while(cin>>n>>m){
        string line;
        getchar();
        for(int i=0;i<n;i++){
            getline(cin,line);
            string cell;
            int m=0;
            for(int c =0;c<line.length();c++){
                 if(line[c]!=',')
                    cell+=line[c];
                 if(line[c]==','||c==line.length()-1){
                     data[i][m] = cell;
                     dic[cell] = 10000*i+m;
                     cell = "";
                     m++;
                 }

             }
        }

        for(int i=0;i<m-1;i++){
            for(int j=i+1;j<m;j++){
                for(int k=0;k<n;k++){
                    int x = dic[data[k][i]];
                    int y = dic[data[k][j]];
                    if(com.count(make_pair(x,y))){
                        cout<<"NO"<<endl;
                        cout<<com[make_pair(x,y)]+1<<" "<<k+1<<endl;
                        cout<<i+1<<" "<<j+1<<endl;
                        goto END;
                    }
                    com[make_pair(x,y)] = k;
                }
                com.clear();
            }
        }
        cout<<"YES"<<endl;
    END:
        memset(data,0, sizeof(data));
        dic.clear();
        com.clear();
    }
    return 0;
}