#include <iostream>
using namespace std;

int main(){
    long long A, B, V;
    cin>>A>>B>>V;
    long long day = A-B;
    V -= B;


    int result;
    if(V%day==0) result = V/day;
    else result = V/day + 1;
    cout<<result<<endl;


    return 0;
}