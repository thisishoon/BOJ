#include <iostream>
#include <algorithm>
using namespace std;

int map[505][505];
int dp[505][505];
int n, dir;
int nexty, nextx;
int result=0;

int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

int go(int y, int x){
    if(dp[y][x]) return dp[y][x];
    dp[y][x]=1;
    for(int i=0; i<4; i++){
        nexty=y+dy[i]; nextx=x+dx[i];
        if(nextx==0 || nextx==n+1 || nexty==0 || nexty==n+1) continue;
        if(map[y][x]<map[nexty][nextx])
            dp[y][x] = max(dp[y][x], go(nexty,nextx)+1);
        
    }
    return dp[y][x];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>map[i][j];
            
        }
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            result=max(result,go(i,j));
        }
    }
    
    
    cout<<result<<endl;
    
    
    return 0;
}

