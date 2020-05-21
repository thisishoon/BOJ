#include <iostream>
#include <algorithm>

using namespace std;

int arr[505][505];
int dp[505][505];
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int visited[505][505];

int n, m;

int dfs(int y, int x){
    if(y==n && x==m)    return 1;

    if(visited[y][x]) return dp[y][x];  //한번 체크한 곳은 다시 체크할 필요 없다.
    visited[y][x]=1;
    for(int d=0; d<4; d++){
        int ny = y+dy[d];
        int nx = x+dx[d];
        if(ny==0 || nx==0 || ny>n || nx>m) continue;
        if(arr[y][x]<=arr[ny][nx]) continue;
        dp[y][x] += dfs(ny, nx);
    }
    return dp[y][x];
}

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>arr[i][j];
        }
    }
    if(n==1 && m==1){
        cout<<"1"<<endl; return 0;
    }
    dfs(1,1);
    cout<<dp[1][1]<<endl;
    

    return 0;
}