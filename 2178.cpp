#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, m;
char arr[111][111];
int visited[111][111];
int result;
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};

void bfs(int y, int x){
    queue<pair<int, int> > q;
    q.push(make_pair(y,x));
    visited[y][x]=1;

    while(!q.empty()){
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        if(curY==n && curX==m){
            result = visited[curY][curX];
            return;
        }

        for(int d=0; d<4; d++){
            int nextY = curY + dy[d];
            int nextX = curX + dx[d];
            if(nextX==0 || nextY==0 || nextX>m || nextY>n) continue;
            if(arr[nextY][nextX]=='0') continue;
            if(visited[nextY][nextX]!=0) continue;

            visited[nextY][nextX]=visited[curY][curX]+1;
            q.push(make_pair(nextY, nextX));
            
        }
    }

}

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin>>arr[i][j];

    bfs(1, 1);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++) 
            cout<<visited[i][j]<<" "; 
        cout<<endl;
    }
         
    cout<<result<<endl;
    return 0;
}