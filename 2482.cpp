#include <iostream>
#include <algorithm>

using namespace std;
int n, k;
int answer;
int dp[1001][1011];     //dp[a][b] = a까지 b개를 선택하는 경우의 수
const int mod = 1000000003;

int main(){
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        dp[i][1]=i;
    }    
    if(k==1){
        cout<<n<<endl;
        return 0;
    }

    for(int i=2; i<=n; i++){
        for(int j=2; j<=k; j++){
            dp[i][j] = (dp[i-2][j-1] + dp[i-1][j])%mod;
        }
    }
    int answer = (dp[n-3][k-1] + dp[n-1][k]) % mod;
    cout<<answer<<endl;

    return 0;
}