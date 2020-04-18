#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int n, s;
char arr[808][808];
int bee[808][808];
queue<pair<int, int> > q;
pair<int, int> house, poo;
int visited[808][808];
int maxMinute=0;
int temp[808][808];

int run(int t){
    memset(visited, 0, sizeof(visited));
    memset(temp, 0, sizeof(temp));
    if(t*s >= bee[poo.first][poo.second]) return false;
    queue<pair<pair<int , int>, int> > q;
    q.push(make_pair(make_pair(poo.first, poo.second), t*s));
    visited[poo.first][poo.second]=1;
    
    while(!q.empty()){
        int y = q.front().first.first;
        int x = q.front().first.second;
        int distance = q.front().second;
        temp[y][x]=distance;
        q.pop();
        if(arr[y][x]=='D') return 1;
        
        for(int d=0; d<4; d++){
            int ny = y + dy[d];
            int nx = x + dx[d];
            if(ny==0 || nx==0 || ny>n || nx>n) continue;
            if(arr[ny][nx]=='T' || arr[ny][nx]=='H') continue;
            if(visited[ny][nx]==1) continue;
            if(bee[ny][nx]>=0 && bee[ny][nx] <= distance+1){
                continue;
            }
            visited[ny][nx]=1;
            q.push(make_pair(make_pair(ny, nx), distance+1));
        }
    }
    return 0;
}

void beeBFS(){
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if(y==poo.first && x==poo.second) maxMinute = bee[y][x];
        for(int d=0; d<4; d++){
            int ny = y + dy[d];
            int nx = x + dx[d];
            if(ny==0 || nx==0 || ny>n || nx>n) continue;
            if(arr[ny][nx]!='G' || bee[ny][nx]!=-1) continue;
            bee[ny][nx] = bee[y][x] + s;
            q.push(make_pair(ny, nx));
        }
    }
}

int main(){
    scanf("%d %d", &n, &s);
    memset(bee, -1, sizeof(bee));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
            if(arr[i][j]=='H') q.push(make_pair(i, j)), bee[i][j]=0;
            else if(arr[i][j]=='D') house.first=i, house.second=j;
            else if(arr[i][j]=='M') poo.first=i, poo.second=j, arr[i][j]='G';
        }
    }
    beeBFS();

    int left = 0; int right = n*n*2; int answer = -1;
    for(;left<right;){
        int mid = (left+right)/2;
        if(run(mid)){
            answer = max(answer, mid);
            left = mid+1;
        }
    
        else right = mid;
    }
    cout<<answer<<endl;

    return 0;
}