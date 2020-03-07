#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int n,m;
char arr[55][55];
int visited[55][55];

int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};
int firstY, firstX;
int lastY, lastX;

int func(int y, int x, int cnt){
    if(cnt>=4){
        if( (abs(firstY-y)==1&&firstX==x) || (abs(firstX-x)==1&&firstY==y) ){
            cout<<"Yes"<<endl;
            exit(0);
            return 10;
        }
    }
    for(int d=0; d<4; d++){
        int nextY = y + dy[d];
        int nextX = x + dx[d];
        if(nextY==0 || nextX==0 || nextY>n || nextX>m) continue;
        if(visited[nextY][nextX]) continue;
        if(arr[y][x]==arr[nextY][nextX]){
            visited[nextY][nextX]=1;
            func(nextY, nextX, cnt+1);
        }
    }
    return 0;
}

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin>>arr[i][j];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            memset(visited, 0, sizeof(visited));
            visited[i][j]=1;
            firstY=i;
            firstX=j;
            int temp = func(i, j, 1);
            // cout<<temp<<"###"<<endl;
        }
    }
    cout<<"No"<<endl;
    return 0;
}