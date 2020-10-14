#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int n, m, sum;
int arr[22][22];
int y, x;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int person[22][22];
vector<pair<int, int> > dest;

int find(){
    int visited[22][22];
    memset(visited, 0, sizeof(visited));
    queue<pair<pair<int, int>, int> > q;
    q.push({{y, x}, 0});
    visited[y][x]=1;
    vector<pair<int, int> > v;

    int minDist = 999999999;
    while(!q.empty()){
        int cy = q.front().first.first;
        int cx = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        if(minDist < dist) break;
        if(arr[cy][cx]>0){
            v.push_back({cy, cx});
            minDist = min(dist, minDist);
            continue;
        }
        if(sum-dist < 0){
            continue;
        }

        for(int d=0; d<4; d++){
            int ny = cy + dy[d];
            int nx = cx + dx[d];
            if(ny<0 || nx<0 || ny==n || nx==n) continue;
            if(arr[ny][nx]==-1) continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx]=1;
            q.push({{ny, nx}, dist+1});
        }
    }

    if(v.size()==0) return -1;
    else{
        sort(v.begin(), v.end());
        int destY = v[0].first;
        int destX = v[0].second;
        int num = arr[destY][destX];
        arr[destY][destX]=0;
        y = destY; x = destX;
        sum = sum - minDist;
        return num;
    }
}

int bfs(int destY, int destX){
    queue<pair<pair<int, int>, int> > q;
    q.push({{y, x}, 0});
    int visited[22][22];
    memset(visited, 0, sizeof(visited));
    visited[y][x] = 1;
    while(!q.empty()){
        int cy = q.front().first.first;
        int cx = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        if(sum - dist < 0){
            break;
        }

        if(cy==destY && cx==destX){
            y = destY; x = destX;
            return dist;
        }
        for(int d=0; d<4; d++){
            int ny = cy + dy[d];
            int nx = cx + dx[d];
            if(ny<0 || nx<0 || ny==n || nx==n) continue;
            if(arr[ny][nx]==-1) continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx]=1;
            q.push({{ny, nx}, dist+1});
        }
    }
    return -1;
}

int main(){
    cin>>n>>m>>sum;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int temp; cin>>arr[i][j];
            if(arr[i][j]) arr[i][j] = -1;
        }
    }
    cin>>y>>x;
    y = y-1;
    x = x-1;
    for(int i=0; i<m; i++){
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        arr[a-1][b-1] = i+1;
        dest.push_back(make_pair(c-1,d-1));
    }
    for(int i=0; i<m; i++){

        int person = find();

        if(person == -1){
            cout<<"-1"<<endl;
            return 0;
        }

        int distance = bfs(dest[person-1].first, dest[person-1].second);

        if(distance!=-1){
            sum = sum + distance;
        }
        else{
            cout<<"-1"<<endl;
            return 0;
        }
        // cout<<sum<<"->"<<endl;
    }
    cout<<sum<<endl;
    return 0;
}