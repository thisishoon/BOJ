#include <iostream>
#include <string>
#include <vector>

using namespace std;

void split(string str){
    vector<string> v;
    for(int i=0; i<str.size(); i++){
        string temp = "";
        if(str[i]==' ') continue;
        else{
            for(int j=i; j<str.size(); j++){
                if(str[j]==' '){
                    i=j;
                    v.push_back(temp);
                    break;
                }
                else if(j == str.size()-1){
                    v.push_back(temp);
                    break;
                }
                temp += str[j];
            }
        }
    }
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    return;
}

int main(){
    string str = "   h ello my name is     jihoon         ";
    split(str);
    
    return 0;
}