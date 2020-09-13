#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <string>
#include <map>
#include <set>
#include <cstdlib>

using namespace std;
int arr[303][303];
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
int answer = 0;
int n;

void dfs(int y, int x, int cnt, int dir){
    // if(cnt==12) return;

    // cout<<y<<" "<<x<<" "<<dir<<endl;
    if(y==n && x==n){
        cout<<cnt<<"정답"<<endl;
        answer = cnt;
        return;
    }
    int ly = y + dy[(dir+1)%4];
    int lx = x + dx[(dir+1)%4];
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    int left = (dir+1)%4;

    if(arr[ny][nx]==1){
        if(dir==0) dir=3;
        else dir = (dir-1)%4;
        dfs( y,  x,  cnt, dir);
    }
    else{
        if(arr[ny+dy[left]][nx+dx[left]]==0){
            dfs( ny,  nx, cnt+1, left);
        }
        else{
            dfs( ny,  nx, cnt+1, dir);
        }
    }
    
    
    
}

int solution(vector<vector<int>> maze) {
    for(int i=0; i<maze.size(); i++){
        for(int j=0; j<maze[0].size(); j++){
            arr[i+1][j+1] = maze[i][j];
        }
    }
    n = maze.size();
    for(int i=0; i<=n+1; i++){
        arr[0][i]=1;
        arr[n+1][i]=1;
        arr[i][0]=1;
        arr[i][n+1]=1;
    }
    
    if(arr[1][2]==1)    dfs(1, 1, 0, 0);
    else dfs(1, 1, 0, 1);
    
    
    
    return answer;
}

int main(){
    vector<vector<int>> maze = {{0, 0, 0, 0, 0, 0}, {1, 1, 1, 0, 1, 1}, {0, 0, 0, 0, 0, 0}, {1, 0, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 0}, {1, 1, 0, 1, 1, 0}};
    solution(maze);
    vector<vector<int>> maze2 = {{0,1,0,1},{0,1,0,0},{0,0,0,0},{1,0,1,0}};
    solution(maze2);
    vector<vector<int> > maze3 = {{0,1,0,0,0,0},{0,0,1,0,0,0},{0,0,0,1,0,0},
    {0,0,0,0,1,0},{0,0,0,0,0,0},{1,1,1,1,1,0}};
    solution(maze3);


}