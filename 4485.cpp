#include <iostream>
#include <queue>
using namespace std;
int t, n;
int arr[150][150];
int visited[150][150];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,-1,1};

int bfs(){
    priority_queue<pair< int, pair<int, int> > > pq;
    pq.push({-arr[0][0], {0,0}});
    while(!pq.empty()){
        int cnt = -pq.top().first;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();
        // cout<<cnt<<" "<<y<<" "<<x<<endl;
        if(visited[y][x]==1) continue;
        visited[y][x]=1;

        if(y==n-1 && x==n-1){
            return cnt;
        }
        for(int d=0; d<4; d++){
            int ny = y+dy[d];
            int nx = x+dx[d];
            if(ny<0 || nx<0 || ny==n || nx==n) continue;
            if(visited[ny][nx]==1) continue;
            pq.push({-(cnt+arr[ny][nx]), {ny, nx}});
        }
    }
    return 0;
}

int main(){
    int i=1;
    
    while(1){
        cin>>n;
        if(n==0) break;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>arr[i][j];
                visited[i][j]=0;
            }
        }
        
        printf("Problem %d: %d\n", i++, bfs());
    }
    return 0;
}