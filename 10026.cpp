#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
char arr[111][111];
int n;
int result1, result2;
int visited[111][111];

void dfs(int y, int x, int flag){
    visited[y][x]=1;
    for(int d=0; d<4; d++){
        if(visited[y+dy[d]][x+dx[d]]) continue;
        if(!flag){
            if(arr[y][x] == arr[y+dy[d]][x+dx[d]]){
                dfs(y+dy[d], x+dx[d], 0);
            }
        }
        else{
            if(arr[y][x] == arr[y+dy[d]][x+dx[d]]){
                dfs(y+dy[d], x+dx[d], 1);
            }
            else if( (arr[y][x]=='R' && arr[y+dy[d]][x+dx[d]]=='G') || (arr[y][x]=='G' && arr[y+dy[d]][x+dx[d]]=='R')){
                dfs(y+dy[d], x+dx[d], 1);
            }
        }
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j]) continue;
            dfs(i, j, 0);
            result1++;
        }
    }
    memset(visited, 0, sizeof(visited));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j]) continue;
            dfs(i, j, 1);
            result2++;
        }
    }
    cout<<result1<<" "<<result2<<endl;


    return 0;
}