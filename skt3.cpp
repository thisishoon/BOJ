#include <string>
#include <iostream>

using namespace std;

string solution(string s){
    string result = "";
    int flag = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='C'){
            flag = !flag;
        }
        else if(s[i]=='B'){
            result.pop_back();
        }
        else{
            if(!flag) result += s[i];
            else{
                result = result + string(1, (toupper(s[i])));
            }
        }
    }
    return result;
}

int main(){
    cout<<solution("abc")<<endl;
    cout<<solution("abCc")<<endl;
    cout<<solution("CabB")<<endl;
    cout<<solution("Cabc")<<endl;
    cout<<solution("ChellBClCo")<<endl;
    cout<<solution("aCbCCcdBefg")<<endl;

}