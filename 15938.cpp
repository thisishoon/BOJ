#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <map>
#include <string.h>

using namespace std;
int firstY, firstX;
int t;
int destY, destX;
int n;
const long long mod = 1000000007;
long long answer;
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int arr[444][444];
int dp[444][444][222];

long long dfs(int time, int y, int x){
    if(y==destY && x==destX) return 1;
    if(time>=t) return 0;

    if(dp[y][x][time]!=-1) return dp[y][x][time];
    dp[y][x][time]=0;
    
    for(int d=0; d<4; d++){
        int ny = y + dy[d];
        int nx = x + dx[d];
        if(ny<0 || nx<0 || ny>400 || nx>400) continue;
        if(arr[ny][nx]==1) continue;
        dp[y][x][time] = (dp[y][x][time] + dfs(time+1, ny, nx) ) %mod;
    }
    return dp[y][x][time]%mod;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin>>firstY>>firstX;
    cin>>t;
    cin>>destY>>destX;
    cin>>n;
    if( (abs(destY-firstY)+abs(destX-firstX)) > 200){
        cout<<answer<<endl;
        return 0;
    }

    for(int i=0; i<n; i++){
        int a, b; cin>>a>>b;
        if(a-firstY+200 >= 0 && a-firstY+200 <=400 && b-firstX+200>=0 && b-firstX+200<=400){
            arr[a-firstY+200][b-firstX+200]=1;
        }
    }
    destY = destY - firstY + 200;
    destX = destX - firstX + 200;
    firstY=200; firstX=200;
    memset(dp, -1, sizeof(dp));

    answer = dfs(0, firstY, firstX);
    
    cout<<answer<<endl;

    return 0;
}