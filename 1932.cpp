#include <iostream>
#include <vector>

using namespace std;

int arr[501][501];
int dp[501][501];

int main(){
    int n; 
    cin>>n;
    int result = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cin>>arr[i][j];
        }
    }
    dp[1][1]=arr[1][1];
    for(int i=2; i<=n; i++){
        for(int j=1; j<=i; j++){
            if(j==1){
                dp[i][j] = arr[i][j] + dp[i-1][j];
            }
            else if(j==i){
                dp[i][j] = arr[i][j] + dp[i-1][j-1];
            }
            else{
                dp[i][j] = arr[i][j] + max(dp[i-1][j-1], dp[i-1][j]);
            }
        }
    }
    for(int i=1; i<=n; i++){
        if(result<dp[n][i]) result = dp[n][i];
    }
    cout<<result<<endl;


    return 0;
}
