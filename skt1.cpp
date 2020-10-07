#include <iostream>

using namespace std;

int solution(string s, int n){
    if(s=="one") return 1*n;
    else if(s=="two") return 2*n;
    else if(s=="three") return 3*n;
    else if(s=="four") return 4*n;
    else return 5*n;
}

int main(){
    cout<<solution("one", 10)<<endl;
    cout<<solution("two", 20)<<endl;
    cout<<solution("five", 44)<<endl;
}