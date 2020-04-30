#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int result[26];
    memset(result, 0, sizeof(result));
    int answer=0;

    string str; cin>>str;
    for(int i=0; i<str.length(); i++){
        char c = str[i];
        if('a'<=c && c<='z'){
            result[c-'a']++;
        }
        else{
            result[c-'A']++;
        }
    }

    int mx=0;
    int mxNum=0;
    for(int i=0; i<26; i++){
        if(mx<result[i]){
            mx=result[i];
            mxNum=i;
        }
    }
    int cnt=0;
    for(int i=0; i<26; i++){
        if(mx==result[i]) cnt++;
    }
    if(cnt>1) cout<<"?"<<endl;
    else cout<<(char)(mxNum+'A')<<endl;
    

    return 0;
}