#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int bit=0;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m; cin>>m;

    for(int i=1; i<=m; i++){
        string str; cin>>str;
        if(str.compare("add")==0){
            int x; cin>>x;
            bit = bit | (1<<x) ;
        }
        else if(str.compare("remove")==0){
            int x; cin>>x;
            bit = bit & ~(1<<x);
        }
        else if(str.compare("check")==0){
            int x; cin>>x;
            if((bit & (1<<x))) cout<<"1\n";
            else cout<<"0\n";
        }
        else if(str.compare("toggle")==0){
            int x; cin>>x;
            if((bit & (1<<x))) bit = bit ^ (1<<x);
            else bit = bit | (1<<x);
            // bit = bit ^ (1<<x);
        }
        else if(str.compare("all")==0){
            bit = (1<<21)-1;
        }
        else if(str.compare("empty")==0){
            bit=0;
        }
    }


    return 0;
}