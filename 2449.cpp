#include <iostream>
#include <algorithm>
using namespace std;

int arr[202];
int dp[202][202];
int main(){
    int n, k;
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            if(i==j) dp[i][j]=0;
            else dp[i][j]=999999999;
        }
    }
    
    // for(int i=2; i<=n; i++){
    //     for(int j=i-1; j>=1; j--){
    //         for(int k=j; k<i; k++){
    //             dp[j][i] = min(dp[j][i], dp[j][k]+dp[k+1][i]+!(arr[k]==arr[i]));
    //         }
    //     }
    // }
    for(int interval=1; interval<n; interval++){ //1칸 짜리
        for(int i=1; i+interval<=n; i++){
            for(int k=i; k<i+interval; k++){
                dp[i][i+interval] = min(dp[i][i+interval], dp[i][k]+dp[k+1][i+interval]+!(arr[i]==arr[k+1]));
            }
        }
    }

    cout<<dp[1][n]<<endl;

    

    return 0;
}