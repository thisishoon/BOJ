#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;
int n, l, r;
int arr[55][55];
int visited[55][55];
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int flag=1;

queue<pair<int, int> > qq;

void BFS(int i, int j){
    if(visited[i][j]==1) return;
    queue<pair<int, int> > q;
    q.push(make_pair(i,j));
    qq.push(make_pair(i,j));
    int sum = arr[i][j];
    visited[i][j]=1;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int d=0; d<4; d++){
            int nextY = y + dy[d];
            int nextX = x + dx[d];
            if(nextY==0 || nextX==0 || nextY>n || nextX>n) continue;
            if(visited[nextY][nextX]==1) continue;
            if(abs(arr[y][x]-arr[nextY][nextX])<l || abs(arr[y][x]-arr[nextY][nextX])>r) continue;
            visited[nextY][nextX]=1;
            q.push(make_pair(nextY, nextX));
            qq.push(make_pair(nextY, nextX));
            sum += arr[nextY][nextX];
            flag=1;
        }
    }
    if(qq.size()>1){
        int avg = sum / qq.size();
        int temp = qq.size();
        for(int i=0; i<temp; i++){
            arr[qq.front().first][qq.front().second] = avg;
            qq.pop();
        }
    }
    else{
        qq.pop();
    }
}

int main(){
    cin>>n>>l>>r;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin>>arr[i][j];
    int answer = 0;

    while(flag){
        flag = 0;
        memset(visited, 0, sizeof(visited));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                BFS(i, j);
            }
        }
        if(flag==1) answer++;
        
    }
    cout<<answer<<endl;

    return 0;
}