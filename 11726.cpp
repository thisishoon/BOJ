#include <iostream>
using namespace std;

long long arr[1001];

int main(){
    int n;
    cin>>n;
    arr[0]=0;
    arr[1]=1;
    arr[2]=2;
    for(int i=3; i<=n; i++){
        arr[i]=(arr[i-1]+arr[i-2])%10007;   //모듈러 연산은 모두 똑같다
    }
    cout<<arr[n]<<endl;

    return 0;
}