#include <iostream>
#include <string>

using namespace std;

int main(){
    string str; cin>>str;
    string bomb; cin>>bomb;
    int size = bomb.size();
    int last_word = bomb.back();
    string result = "";

    for(int i=0; i<str.size(); i++){
        result += str[i];
        if(str[i]==last_word){
            int flag = 0;
            for(int j=1; j<=size; j++){
                if(result[result.size()-j] != bomb[size-j]){
                    flag = 1;
                    break;
                }
            }
            if(flag) continue;
            else{
                for(int j=1; j<=size; j++){
                    result.pop_back();
                }
            }
        }
    }
    if(result.empty()) cout<<"FRULA"<<endl;
    else cout<<result<<endl;

    return 0;
}