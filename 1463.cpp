#include <iostream>
#include <algorithm>
using namespace std;

int dp(int n){
    if(n<2) return 0;
    // int result = dp(n-1)+1;
    // if(n%3==0) result = min(dp(n/3)+1, result);
    // if(n%2==0) result = min(result, dp(n/2)+1);
    int result = dp(n/3)+ n%3 +1;
    result = min(result, dp(n/2)+ n%2 +1);
    return result;
}

int arr[1000001];
int main(){
    int n;
    cin>>n;
    /*
    arr[1]=0;
    arr[2]=arr[3]=1;
    for(int i=4; i<=n; i++){
        arr[i] = arr[i-1]+1;
        if(i%2==0) arr[i]=min(arr[i], arr[i/2]+1);
        if(i%3==0) arr[i]=min(arr[i], arr[i/3]+1);
    }
    cout<<arr[n]<<endl;
    */
    cout<<dp(n)<<endl;
    return 0;
}