#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

long long k;
int dp[202][202];
int n,m;

int main(){
    cin>>n>>m>>k;

    for(int i=0; i<=(m+n); i++){
        dp[i][0]=1;
        dp[i][i]=1;
    }

    for(int i=2; i<=m+n; i++){
        for(int j=1; j<i; j++){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            if(dp[i][j]>1000000000) dp[i][j]=1000000000;
        }
    }

    // for(int i=1; i<=m+n; i++){
    //     for(int j=1; j<=i; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    if(dp[n+m][m]<k){
        cout<<"-1"<<endl;
        return 0;
    }
    string str="";
    int cnt=0; int size = n+m;

    while (cnt < size)
        {
            if (k <= dp[n + m - 1][m])
            {
                //a로 시작함
                str+='a';
                n--; //a를 하나 썼으니까
            }
            else {
                k-= dp[n+m-1][m];
                str+='z';
                m--;
            }
            cnt++;
        }
    cout<<str<<endl;

    return 0;
}
