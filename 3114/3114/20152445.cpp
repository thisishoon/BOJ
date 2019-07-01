
#include <iostream>
using namespace std;
int a[1505][1505], b[1505][1505], dp[1505][1505], asum[1505][1505], bsum[1505][1505];
int main(){
    int y,x;
    char fruit; int num;
    cin>>y>>x;
    for(int i=1; i<=y; i++){   //입력
        for(int j=1; j<=x; j++){
            cin>>fruit>>num;
            if(fruit=='A') a[i][j]=num;
            else if(fruit=='B') b[i][j]=num;
        }
    }
    for (int i = 1; i <= y; i++) {  //시간초과를 안하기위해 미리 구해놓기
        for (int j = 1; j <= x; j++)
            asum[i][j] = asum[i][j-1] + a[i][j];
        for (int j=x; j>=1; j--)
            bsum[i][j] = bsum[i][j+1] + b[i][j];
    }
    for(int i=1; i<=y; i++) // x=1일 떄 초기화
        dp[i][1]=dp[i-1][1] + bsum[i][2];
    for(int j=2; j<=x; j++) // y=1일 떄 초기화
        dp[1][j]=bsum[1][j+1];
    
    for (int i = 2; i <= y; i++) {
        for (int j = 2; j <= x; j++) {
            dp[i][j] = max(dp[i][j-1] -b[i][j], max(dp[i-1][j-1]+asum[i][j-1]+bsum[i][j+1], dp[i-1][j]+asum[i][j-1]+bsum[i][j+1]));
        }
    }
    
    cout<<dp[y][x];
    return 0;
}

