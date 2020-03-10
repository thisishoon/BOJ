#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int arr[51][51];
int visited[51][51];
int direction;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int startY, startX;
int result=1;
int rotate_num;

int main(){
    cin>>n>>m;
    cin>>startY>>startX>>direction;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin>>arr[i][j];
    
    startY++; startX++;

    visited[startY][startX]=1;

    while(1){
        if(rotate_num==4){
            rotate_num=0;
            startY = startY - dy[direction];
            startX = startX - dx[direction];
            
            if(arr[startY][startX]==1 || startY==0 || startX==0 || startY>n || startX>m){
                cout<<result<<endl;
                break;
            }
        }
        
        int nextY = startY + dy[(direction+3)%4];
        int nextX = startX + dx[(direction+3)%4];
        direction = (direction+3)%4;
        rotate_num++;
        
        if(nextY==0 || nextX==0 || nextY>n || nextX>m) continue;
        if(visited[nextY][nextX]==1) continue;
        if(arr[nextY][nextX]==1) continue;
        // cout<<"@"<<endl;
        // cout<<nextY<<" "<<nextX<<"청소"<<endl;
        visited[nextY][nextX]=1;
        startY = nextY; startX = nextX;
        result++;
        rotate_num=0;
    }
    
    return 0;
}