#include <iostream>
#include <algorithm>

using namespace std;
int arr[100001];
int dp[100001];

int main(){
    int n;
    int result=-1001;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    for(int i=1; i<=n; i++){
        if(dp[i-1]+arr[i]>arr[i]){
            dp[i]=arr[i]+dp[i-1];
        }
        else dp[i]=arr[i];
        if(result<dp[i]) result = dp[i];
    }
    cout<<result<<endl;
    
    


    return 0;
}