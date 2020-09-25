#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n;
int arr[11][11];
int visited[11][11];
vector<int> v;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

int bfs(int y, int x){

    if(visited[y][x]) return 0;
    if(arr[y][x]==0) return 0;
    queue<pair<int, int> > q;

    q.push(make_pair(y,x));
    visited[y][x]=1;
    int size = 0;
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        size ++;
        
        for(int d=0; d<4; d++){
            int ny = i + dy[d];
            int nx = j + dx[d];
            if(ny<0 || nx<0 || ny==n || nx==n) continue;
            if(visited[ny][nx]==1) continue;
            if(arr[ny][nx]==0) continue;

            q.push(make_pair(ny, nx));
            visited[ny][nx]=1;
        }

    }
    v.push_back(size);

    return 0;
}



int main(){
    cin>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>arr[i][j];

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            bfs(i, j);
    
    sort(v.begin(), v.end());
    cout<<v.size()<<endl;
    for(int i : v){
        cout<<i<<" ";
    }
    
}