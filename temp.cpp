#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct point{
    int x;
    int y;
}p;
int arr[10][10];
int visited[10][10];
queue<point> q;
int n, m;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void bfs(point p){
    q.push(p);
    visited[p.x][p.y]=1;

    while(!q.empty()){
        point p = q.front();
        q.pop();
        visited[p.x][p.y]=1;
        for(int i=0; i<4; i++){
            int nx=p.x+dx[i];
            int ny=p.y+dy[i];

            if(nx<0 || nx==n || ny<0 || ny==m) continue;
            if(visited[nx][ny] != 0) continue;
            visited[nx][ny] = 1;

            point next={nx,ny};
            q.push(next);
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]==2){
                point virus={i,j};
                bfs(virus);
            }
        }
    }
    return 0;
}