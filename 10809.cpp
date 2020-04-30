#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int result[26];
    memset(result, -1, sizeof(result));
    string str;
    cin>>str;
    for(int i=0; i<str.length(); i++){
        char c = str[i];
        if(result[c-97]==-1)
            result[c-97]=i;
    }
    for(int i=0; i<26; i++){
        cout<<result[i]<<" ";
    }
    


    return 0;
}