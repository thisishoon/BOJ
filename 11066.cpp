#include <iostream>
#include <algorithm>

using namespace std;
int arr[505];

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int dp[505][505];
        int sum[505];
        for(int i=1; i<=n; i++){
            scanf("%d", &arr[i]);
            sum[i] = sum[i-1] + arr[i];
        }
        for(int m=1; m<n; m++){ //[a,b]의 거리 = m
            for(int i=1; i<=n-m+1; i++){    //a= 1, 2, 3 ... n-m+1
                int a = i; int b = i + m;   //b= 1+m, 2+m, 3+m ... n
                dp[a][b]=999999999;
                for(int k=a; k<=b; k++){     //k= a, a+1, a+2, ... b-1
                    dp[a][b] = min(dp[a][b], dp[a][k]+dp[k+1][b]+sum[b]-sum[a-1]);
                }
            }
        }
        cout<<dp[1][n]<<endl;
    }


    return 0;
}