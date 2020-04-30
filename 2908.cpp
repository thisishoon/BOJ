#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    string str1, str2;
    cin>>str1>>str2;
    int num1=0;
    int num2=0;
    for(int i=0, d=1; i<str1.length(); i++, d*=10){
        num1 += ((str1[i]-48) *d);
    }
    for(int i=0, d=1; i<str2.length(); i++, d*=10){
        num2 += ((str2[i]-48) *d);
    }
    cout<<num1<<" "<<num2<<endl;
    cout<<max(num1, num2)<<endl;

    return 0;
}