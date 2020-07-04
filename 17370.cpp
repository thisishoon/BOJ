#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n;
int dy[6]={1, 1, -1, -1 ,-1, 1};
int dx[6]={0, 1, 1, 0, -1, -1};
int visited[100][100];
int answer;

void backtrack(int y, int x, int pre, int cnt){
    // cout<<y<<" "<<x<<endl;
    if(cnt>n) return;
    if(visited[y][x]==1){
        if(cnt==n) answer++;
        return;
    }
    visited[y][x]=1;
    
    for(int d=0; d<2; d++){
        int ny, nx, nd;
        if(d==0){
            nd = (pre+1)%6;
            ny = y + dy[nd];
            nx = x + dx[nd];
        }
        else{
            nd = (pre+5)%6;
            ny = y + dy[nd];
            nx = x + dx[nd];
        }

        backtrack(ny, nx, nd, cnt+1);
    }

    visited[y][x]=0;
    return;
}

int main(){
    cin>>n;
    visited[25][25]=1;
    backtrack(26, 25, 0, 0);
    cout<<answer<<endl;

    return 0;
}