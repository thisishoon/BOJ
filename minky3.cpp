#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int arr[6][6];

int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int visited[4][4];
int result;

void dfs(int y, int x, int num){
    if(result<num) result = num;
    for(int i=0; i<4; i++){
        int nextY = y+dy[i];
        int nextX = x+dx[i];
        if(nextY>0 && nextY<=4 && nextX>0 && nextX<=4){
            if(visited[nextY][nextX]==0){
                if(arr[y][x]==arr[nextY][nextX]){
                    visited[nextY][nextX]=1;
                    dfs(nextY, nextX, num+1);
                    visited[nextY][nextX]=0;
                }
            }
        }
    }
    //return;
}

int main(){
    int solution=0;
    for(int i=1; i<=4; i++){
        for(int j=1; j<=4; j++){
            cin>>arr[i][j];
        }
    }
    for(int i=1; i<=4; i++){
        for(int j=1; j<=4; j++){
            memset(visited, 0, sizeof(visited));
            visited[i][j]=1;
            dfs(i,j,1);
            solution=max(solution, result);
        }
    }
    if(solution==1) cout<<"-1"<<endl;
    else cout<<solution<<endl;

    return 0;
}

// 3 2 3 2
// 2 1 1 2
// 1 1 2 1
// 4 1 1 1