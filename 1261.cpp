#include <iostream>
#include <queue>
#include <utility>
#include <tuple>
using namespace std;
int n, m;
int arr[111][111];
int visited[111][111];
int answer=0;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

void bfs(int i, int j){
    priority_queue<pair<int, pair<int, int> > > pq;
    pq.push({0, {i, j}});

    while(!pq.empty()){
        int cnt = -pq.top().first;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();
        // cout<<y<<" "<<x<<endl;

        if(visited[y][x]==1) continue;

        if(y==n && x==m){
            answer = cnt;
            cout<<answer<<endl;
            return;
        }
        visited[y][x]=1;

        for(int d=0; d<4; d++){
            int ny = y + dy[d];
            int nx = x + dx[d];
            // cout<<y<<" "<<x<<" "<<ny<<" "<<nx<<endl;
            if(ny==0 || nx==0 || ny>n || nx>m) continue;
            if(visited[ny][nx]==1) continue;
            // visited[ny][nx]=1;
            if(arr[ny][nx]==1){
                pq.push({-(cnt+1), {ny, nx}});
            }
            else{
                pq.push({-(cnt), {ny, nx}});
            }
        }
    }
    return ;
}

int main(){
    cin>>m>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%1d", &arr[i][j]);
        }
    }
    bfs(1,1);
    return 0;
}