#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int dp[100001][2];

int main(){
    int n; scanf("%d", &n);
    for(int i=1; i<=n; i++){
        int temp;
        scanf("%d", &temp);
        arr[i] = temp;
        
    }
    if(n==1){
        printf("%d", arr[1]);
        return 0;
    }
    
    dp[1][0]=dp[1][1]=arr[1];

    for(int i=2; i<=n; i++){
        dp[i][0] = max(dp[i-1][0]+arr[i], arr[i]);
        dp[i][1] = max(dp[i-1][0], dp[i-1][1]+arr[i]);
    }

    int result= -999999999;
    for(int i=1; i<=n; i++)
        result=max(max(result, dp[i][0]), dp[i][1]);
    
    printf("%d", result);

    return 0;
}