#include <iostream>
#include <limits.h>

using namespace std;
long long answer = LLONG_MAX;
pair<int, int> arr[505];
long long dp[505][505]; //dp[a][b] 는 a번쨰부터 b번째 행렬까지 곱했을 때 최소 곱셈 연산 횟수 [a,b]

int main(){
    int n; cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i].first>>arr[i].second;
    }
    
    for(int i=1; i<n; i++){
        dp[i][i+1] = arr[i].first*arr[i].second*arr[i+1].second;
    }
    
    for(int m=2; m<=n-1; m++){
        for(int i=1; i<=n-m; i++){
            int a=i; int b=i+m;
            dp[a][b]=LLONG_MAX;
            for(int k=a; k<b; k++){             
                dp[a][b] = min(dp[a][b], dp[a][k]+dp[k+1][b]+ arr[a].first * arr[k].second * arr[b].second);
            }
        }
    }

    cout<<dp[1][n]<<endl;

    return 0;
}