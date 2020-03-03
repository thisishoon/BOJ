#include <iostream>
#include <algorithm>

using namespace std;
int n, m; 
int arr[505][505];
int visited[505][505];
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int result;
int solution;
void dfs(int y, int x, int count){
    if(count==3){
        solution = max(solution, result);
        return;
    }
    for(int d=0; d<4; d++){
        int nextY=y+dy[d];
        int nextX=x+dx[d];
        if(nextX==0 || nextY==0 || nextX>m || nextY>n) continue;
        if(visited[nextY][nextX]==1) continue;
        result += arr[nextY][nextX];
        visited[nextY][nextX]=1;
        dfs(nextY, nextX, count+1);
        result -= arr[nextY][nextX];
        visited[nextY][nextX]=0;
    }

    //return 0;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) scanf("%d", &arr[i][j]);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            result = arr[i][j];
            visited[i][j]=1;
            dfs(i, j, 0);
            visited[i][j]=0;
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(i-1>=1 || i+1 <=n || j-1>=1)
                solution = max(solution, arr[i][j]+arr[i-1][j]+arr[i+1][j]+arr[i][j-1]);
            if(i-1>=1 || i+1 <=n || j+1<=m)
                solution = max(solution, arr[i][j]+arr[i-1][j]+arr[i+1][j]+arr[i][j+1]);
            if(j-1>=1 || j+1 <=m || i-1>=1)
                solution = max(solution, arr[i][j]+arr[i][j-1]+arr[i][j+1]+arr[i-1][j]);
            if(j-1>=1 || j+1 <=m || i+1<=n)
                solution = max(solution, arr[i][j]+arr[i][j-1]+arr[i][j+1]+arr[i+1][j]);
        }
    }

    cout<<solution<<endl;
    return 0;
}



/*
4 4
0 0 0 0
2 2 2 2
0 0 0 0 
0 0 0 0
*/