#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <set>
//#define LOCAL
using namespace std;
typedef vector<string> list;


void decodeAddress(string& s,string& sender,string& recipient){
    int index = s.find("@");
    sender = s.substr(0,index);
    recipient = s.substr(index+1,s.length());
}

int main(){
#ifdef LOCAL
    freopen("/Users/arlex/Documents/Project/C:C++/AlgorithmLearning/Learning/TheLetterRounds.txt","r",stdin);
#endif
    set<string> mtas;
    string s,sender,receiver,sendmta,receivemta;
    while(cin>>s&&s!="*"){
        string location;
        int number;
        cin>>location>>number;
        while(number--){
            cin>>s;
            mtas.insert(s+"@"+location);
        }
    }

    while(cin>>s&&s!="*"){
        map<string,vector<string> > recipients;
        vector<string> mtaorder;
        set<string> vis;
        decodeAddress(s,sender,sendmta);
        while(cin>>s&&s!="*"){
            decodeAddress(s,receiver,receivemta);
            if(vis.count(s)){
                continue;
            }
            vis.insert(s);
            if(recipients.count(receivemta)){
                recipients[receivemta].push_back(s);
            }else{
                mtaorder.push_back(receivemta);
                vector<string> v;
                v.push_back(s);
                recipients[receivemta]=v;
            }
        }
        string t;
        getline(cin,t);
        string content;
        //正文部分
        while(getline(cin,t)&&t[0]!='*'){
            content +="     "+t+"\n";
        }
        for(int i=0;i<recipients.size();i++){
            receivemta = mtaorder[i];
            bool ok = false;
            cout<<"Connection between "<<sendmta<<" and "<<receivemta<<endl;
            cout<<"     HELO "<<sendmta<<endl;
            cout<<"     250"<<endl;
            cout<<"     MAIL FROM:<"<<sender<<"@"<<sendmta<<">"<<endl;
            cout<<"     250"<<endl;
            vector<string> receivers = recipients[receivemta];
            for(int j=0;j<receivers.size();j++){
                cout<<"     RCPT TO:<"<<receivers[j]<<">"<<endl;
                if(mtas.count(receivers[j])){
                    ok = true;
                    cout<<"     250"<<endl;
                }else{
                    cout<<"     550"<<endl;
                }
            }
            if(ok){
                cout<<"     DATA"<<endl;
                cout<<"     354"<<endl;
                cout<<content;
                cout<<"     ."<<endl;
                cout<<"     250"<<endl;
            }
            cout<<"     QUIT"<<endl;
            cout<<"     221"<<endl;
        }

    }




    return 0;
}