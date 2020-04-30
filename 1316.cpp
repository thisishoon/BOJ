#include <iostream>
#include <cstring>
#include <map>
using namespace std;
int main(){
    int answer=0;
    int n; cin>>n;
    for(int i=1; i<=n; i++){
        string str; cin>>str;
        map<char, int> s;
        int flag=1;
        for(int i=0; i<str.length(); i++){
            char c = str[i];
            if(s[c]){
                flag=0; break;
            }
            else{
                s[c]++;
                for(int j=i+1; j<str.length(); j++){
                    if(str[j]==c) i++;
                    else break;
                }
            }
        }
        if(flag) answer++;
    }
    cout<<answer<<endl;
    return 0;
}