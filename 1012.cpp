#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;
int m, n, k;
int arr[51][51];
int visited[51][51];
int dy[4]={0, 0, 1, -1};
int dx[4]={1, -1, 0, 0};

void bfs(int y, int x){
    queue<pair<int, int> > q;
    q.push(make_pair(y,x));
    visited[y][x]=1;
    while(!q.empty()){
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int next_y = cur_y + dy[i];
            int next_x = cur_x + dx[i];
            if(next_y<0 || next_x<0 || next_y>=n || next_x>=m) continue;
            
            if(arr[next_y][next_x]==1){
                if(visited[next_y][next_x]==0){
                        visited[next_y][next_x]=1;
                        q.push(make_pair(next_y, next_x));
                }
            }
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        memset(arr, false, sizeof(arr));
        memset(visited, false, sizeof(visited));

        int result=0;
        cin>>m>>n>>k;
        for(int i=0; i<k; i++){
            int a, b;
            cin>>a>>b;
            arr[b][a]=1;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j]==1 && visited[i][j]==0){
                    //cout<<i<<","<<j<<endl;
                    bfs(i,j);
                    result++;
                }
            }
        }
        cout<<result<<endl;
    }
    return 0;
}