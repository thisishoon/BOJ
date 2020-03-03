#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 1000000007;
long long factorial[4000004];

long long func(int a, int exp){
    if(exp==1) return a%mod;
    long long half = func(a, exp/2);
    long long result = (half*half)%mod;
    if(exp%2) result = (result*a)%mod;
    return result;
}

int main(){
    int n, k; cin>>n>>k;
    if(k==0 || n==k){
        cout<<"1"<<endl;
        return 0;
    }
    factorial[1]=1;
    for(int i=2; i<=4000000; i++)
        factorial[i] = (factorial[i-1]*i)%mod;

    int top = factorial[n];
    int bottom_left = factorial[k];
    int bottom_right = factorial[n-k];
    long long bottom = (1LL*bottom_left*bottom_right)%mod;
    int exp = mod;
    //cout<<top<<" "<<bottom<<endl;
    long long base = func(bottom, exp-2);
    long long result = (top)*(base)%mod;
    cout<<result<<endl;
    return 0;
}