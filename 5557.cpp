#include <iostream>
#include <algorithm>

using namespace std;
int n;
int arr[111];
//dp[a][b] = a번째까지 사용하여 b를 만들 수 있는 방법의 수
long long dp[111][22];
int goal;

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    goal = arr[n];
    dp[1][arr[1]] = 1;
    
    for(int i=2; i<n; i++){
        for(int j=0; j<=20; j++){
            if(dp[i-1][j]!=0){
                if(j+arr[i]>=0 && j+arr[i]<=20){
                    dp[i][j+arr[i]] += dp[i-1][j];
                }
                if(j-arr[i]>=0 && j-arr[i]<=20){
                    dp[i][j-arr[i]] += dp[i-1][j];
                }
            }
        }
    }
    cout<<dp[n-1][goal]<<endl;
    
    
    

    return 0;
}