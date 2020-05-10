#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int l, n, m;
char arr[33][33][33];
int visited[33][33][33];
pair<int, int> start;
int startFloor;

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};


int bfs(int i, int j){
    priority_queue<pair<pair<int, int> , pair<int, int> > >pq;
    memset(visited, 0, sizeof(visited));
    pq.push({{0,startFloor}, {i,j}});
    while(!pq.empty()){
        int cnt = -pq.top().first.first;
        int f = pq.top().first.second;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();
        if(arr[f][y][x]=='E'){
            return cnt;
        }
        if(visited[f][y][x]==1) continue;
        visited[f][y][x]=1;
        for(int d=0; d<4; d++){
            int ny = y + dy[d];
            int nx = x + dx[d];
            if(ny==0 || nx==0 || ny>n || nx>m) continue;
            if(visited[f][ny][nx]==1) continue;
            if(arr[f][ny][nx]=='#'){
                continue;
            }
            pq.push({ {-(cnt+1),f}, {ny,nx} });
        }
        for(int i=0; i<2; i++){
            int nf;
            if(i==0) nf = f+1;
            else nf = f-1;
            if(nf<=0 || nf>l) continue;
            if(visited[nf][y][x]==1) continue;
            if(arr[nf][y][x]=='#') continue;
            pq.push({ {-(cnt+1), nf}, {y, x} });
        }
    }
    return -1;
}

int main(){
    while(1){
        cin>>l>>n>>m;
        if(l==0 && n==0 && m==0) break;
        for(int f=1; f<=l; f++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=m; j++){
                    cin>>arr[f][i][j];
                    if(arr[f][i][j]=='S'){
                        start.first = i; start.second=j;
                        startFloor=f;
                    }
                }
            }
        }
        int flag = bfs(start.first, start.second);
        if(flag!=-1) printf("Escaped in %d minute(s).\n", flag);
        else printf("Trapped!\n");
    }
    return 0;
}