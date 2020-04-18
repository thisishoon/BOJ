#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
int arr[20][20];
int result;
int n;
int dy[3] = {0,1,1};    //가로, 세로, 대각 순
int dx[3] = {1,0,1};

void dfs(int y, int x, int state){  // 가로 d=0; 세로 d=1; 대각 d=2;
    if(y==n && x==n){
        result++;
        return;
    }
    // cout<<y<<" "<<x<<" "<<state<<endl;
    for(int d=0; d<3; d++){
        int nextY = y+dy[d];
        int nextX = x+dx[d];
        if(state==0&&d==1 || state==1&&d==0){
            continue;
        }
        if(nextY>n || nextX>n || arr[nextY][nextX]==1){
            continue;
        }
        if(d==2 && (arr[y+1][x]==1 || arr[y][x+1]==1) ){
            continue;
        }
        dfs(nextY, nextX, d);
    }
}

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
        }
    }
    dfs(1, 2, 0);
    cout<<result<<endl;

    return 0;
}