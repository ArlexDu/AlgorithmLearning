#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
#define LOCAL
using namespace std;
typedef vector<string> list;
struct Building{
    int id;
    double x,y,width,depth,height;
    bool operator < (const Building& building) const{
        return x<building.x||(x==building.x&&y<building.y);
    }
};
const int maxn = 105;

Building building[maxn];
double x[maxn*2];
int number;

bool cover(int i, double pos){
    return building[i].x<=pos&&(building[i].x+building[i].width)>=pos;
}

bool visible(int i, double pos){
    if(!cover(i,pos))
        return false;
    for(int t=0;t< number;t++){
        if(!cover(t,pos))
            continue;
        if(building[t].y<building[i].y&&building[t].height>=building[i].height)
            return false;
    }
    return true;
}

int main(){
#ifdef LOCAL
    freopen("/Users/arlex/Documents/Project/C:C++/AlgorithmLearning/Learning/UrbanElevations.txt","r",stdin);
#endif
    int map_number = 0;
    number = 0;
    while(cin>>number&&number!=0){
        int count = 0;
        memset(building,0,maxn);
        int n = number;
        while(n--){
            building[count].id = count+1;
            cin>>building[count].x;
            cin>>building[count].y;
            cin>>building[count].width;
            cin>>building[count].depth;
            cin>>building[count].height;
            x[count*2] = building[count].x;
            x[count*2+1] = building[count].x+building[count].width;
            count++;
        }
        sort(building,building+number);
        sort(x,x+number*2);
        //unique函数返回指向超出无重复的元素范围末端的下一个位置
        int m = unique(x,x+number*2) - x;

        if(map_number++)
            cout<<endl;
        cout<<"For map #"<<map_number<<", the visible buildings are numbered as follows:"<<endl;
        cout<<building[0].id;
        for(int i=1;i<number;i++){
            int id = building[i].id;
            for(int j=0;j<m-1;j++){
                double pos = (x[j]+x[j+1])/2;
                if(visible(i,pos)){
                    cout<<" "<<building[i].id;
                    break;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}