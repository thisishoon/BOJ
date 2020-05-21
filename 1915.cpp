#include <iostream>

using namespace std;

int arr[1011][1011];
int dp[1011][1011];
int n, m;
int answer;

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%1d", &arr[i][j]);
            if(arr[i][j]==1) dp[i][j]=1;
        }
    }    
    for(int k=2; k<=n; k++){    //m은 정사각형의 사이즈
        for(int i=1; i<=n-k+1; i++){
            for(int j=k; j<=m; j++){
                if(i==3 && j==3){
                }
                if(dp[i][j-1]>=k-1 && dp[i+1][j]>=k-1 && dp[i+1][j-1]>=k-1 && dp[i][j]>=k-1){
                    dp[i][j]=k;
                }
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            answer = max(answer, dp[i][j]);
            // cout<<dp[i][j]<<" ";
        }
        // cout<<endl;
    }
    cout<<answer*answer<<endl;

    return 0;
}