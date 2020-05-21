#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;
set<int> s;

int main(){
    int m; cin>>m;

    for(int i=1; i<=m; i++){
        string str; cin>>str;
        if(str.compare("add")==0){
            int x; cin>>x;
            s.insert(x);
        }
        else if(str.compare("remove")==0){
            int x; cin>>x;
            s.erase(x);
        }
        else if(str.compare("check")==0){
            int x; cin>>x;
            if(s.find(x)!=s.end()) cout<<"1\n";
            else cout<<"0"<<endl;
        }
        else if(str.compare("toggle")==0){
            int x; cin>>x;
            if(s.find(x)!=s.end()) s.erase(x);
            else s.insert(x);
        }
        else if(str.compare("all")==0){
            s.clear();
            for(int i=1; i<=20; i++){
                s.insert(i);
            }
        }
        else if(str.compare("empty")==0){
            s.clear();
        }
    }


    return 0;
}