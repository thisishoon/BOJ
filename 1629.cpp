#include <iostream>
#include <algorithm>
using namespace std;

int a, b, c;

long long power(int n, int k){
    
    if(k==1){
        return n;
    }
    long long temp = power(n,k/2);
    long long result = 0;
    if(k%2==0){ //짝수
        result = (((1LL*temp)%c)*temp)%c;
    }
    else{   //홀수
        result = (((1LL*temp)%c)*temp)%c;
        result = (result*n)%c;
    }
    return result;
}

int main(){
    cin>>a>>b>>c;
    cout<<power(a,b)<<endl;
    return 0;
}