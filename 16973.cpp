#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, m;
int arr[1011][1011];
int visited[1011][1011];
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int height, weight, Sr, Sc, Fr, Fc;
int result=2147000000;

// void dfs(int y, int x, int cnt){
//     if(y==Fr && x==Fc){
//         result = min(result, cnt);
//         return;
//     }
//     for(int d=0; d<4; d++){
//         int nextY=y+dy[d];
//         int nextX=x+dx[d];
//         int flag=0;
//         if(visited[nextY][nextX]==1) continue;
//         for(int i=0; i<height; i++){    //직사각형 순회
//             for(int j=0; j<weight; j++){
//                 int a = nextY + i;
//                 int b = nextX + j;
//                 if(a<1 || b<1 || a>n || b>m){
//                     flag=1;
//                     break;
//                 }
//                 if(arr[a][b]==1){
//                     flag=1;
//                     break;
//                 }
//             }
//         }

//         if(flag==0){
//             visited[nextY][nextX]=1;
//             dfs(nextY, nextX, cnt+1);
//             //visited[nextY][nextX]=0;
//         }
//         else continue;
//     }
//     return;
// }
struct node{
    int y;
    int x;
    int count;
};

int check_area(int y, int x){
    if(y+height-1>n || x+weight-1>m) return 0;
    
    for(int i=0; i<height; i++){
        if(arr[y+i][x]==1) return 0;
        if(arr[y+i][x+weight-1]==1) return 0;
    }
    
    for(int j=0; j<weight; j++){
        if(arr[y][x+j]==1) return 0;
        if(arr[y+height-1][x+j]==1) return 0;
    }
    
    return 1;
}

void bfs(int a, int b){
    // cout<<a<<" "<<b<<endl;
    queue<node> q;
    node temp;
    temp.y = a; temp.x = b; temp.count=0;
    q.push(temp);
    while(!q.empty()){
        int y = q.front().y;
        int x = q.front().x;
        int cnt = q.front().count;
        // cout<<"시작"<<y<<" "<<x<<endl;
        q.pop();
        if(y==Fr && x==Fc){ //성공했을 경우 리턴
            result=cnt;
            return;
        }
        for(int d=0; d<4; d++){ //4방향
            int nextY=y+dy[d];
            int nextX=x+dx[d];
            // cout<<"다음"<<nextY<<" "<<nextX<<endl;
            if(nextY<1 || nextX<1 || nextY>n || nextX>m) continue;
            if(visited[nextY][nextX]==1) continue;
            // cout<<nextY<<" "<<nextX<<endl;
            int flag = check_area(nextY, nextX);

            if(flag==1){
                visited[nextY][nextX]=1;
                node next;
                next.y= nextY; next.x=nextX; next.count=cnt+1;
                q.push(next);
            }
            else continue;
        }
    }
    return;
}


int main(){
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    scanf("%d %d %d %d %d %d", &height, &weight, &Sr, &Sc, &Fr, &Fc);
    if(Sr==Fr && Sc==Fc) {
        cout<<"0"<<endl;
        return 0;
    }
    visited[Sr][Sc]=1;
    bfs(Sr, Sc);
    if(result==2147000000) cout<<"-1"<<endl;
    else cout<<result<<endl;

    return 0;
}



/*
3 3
0 0 0  
0 0 0
0 0 0
1 1 1 1 2 2
*/