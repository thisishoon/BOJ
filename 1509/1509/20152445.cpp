#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;

char input[2505];
bool chk[2505][2505];
int dp[2505];

int main(){
    cin>> (input+1);
    int n = int(strlen(input+1));
    
    
    
    for(int i=1; i<=n; i++) chk[i][i]=1;
    //changed matrix multiplication을 이용한 chk[n][n]배열 초기화
    
    for(int i=1; i<n; i++)
        if(input[i]==input[i+1]) chk[i][i+1]=1;
    
    for(int diagonal=2; diagonal<= n-1; diagonal++){
        for(int i=1; i<=n-diagonal; i++){
            int j= i+ diagonal;
            if(input[i] == input[j]){   //input[i]와 input[j]가 같다면
                chk[i][j]=chk[i+1][j-1];  //끝자리의 문자를 뺴고 확인
            }
        }
    }
    
    dp[0]=0;
    
    //dp[i]는 i번쨰 까지의 팰린드롬의 최소 분할 수
    //   0   [ { (1, 2, ..., j-1) j, ..., i }, ..., n-1, n ]
    for(int i=1; i<=n; i++){
        dp[i]=99999;
        for(int j=1; j<=i; j++){
            if(chk[j][i]){
                if(dp[i] > dp[j-1] + 1)
                    dp[i]=dp[j-1]+1;
            }
        }
    }
    
    
    cout<<dp[n];
    
    
    return 0;
}
