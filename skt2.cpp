#include <iostream>
#include <string>

using namespace std;

string solution(string str){
    string s = "";
    string m = "";
    string l = "";

    for(char temp : str){
        if(temp== 's') s += temp;
        else if(temp== 'm') m+=temp;
        else l += temp;
    }
    string result = s + m + l;
    return s+m+l;
    
}

int main(){

    cout<<solution("LSM")<<endl;
    cout<solution("SSSSMLSMLSMLSS") <<endl;
}