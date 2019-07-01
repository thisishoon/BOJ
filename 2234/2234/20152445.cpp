#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string.h>
using namespace std;

int map[55][55];
bool visited[55][55];
int dy[4]={0,-1,0,1};  //****서->북->동->남 으로 설정해야함!!!!!
int dx[4]={-1,0,1,0};

int n,m;
int result1, result2, result3;

struct point{
    point(int y, int x) : y(y), x(x) {}
    int y; int x;
};

bool check(int y,int x){
    if(0<y && 0<x && y<=n && x<=m) return true;
    else return false;
}

int bfs(int first_y, int first_x){
    int room_size=1;
    queue<point> q;
    q.push(point(first_y,first_x));
    visited[first_y][first_x]=true;
    
    //cout<<"비어있는 방의 시작"<<first_y<<","<<first_x<<endl;
    while(!q.empty()){
        int y=q.front().y;
        int x=q.front().x;
        q.pop();
        
        for(int d=0; d<4; d++){
            if( map[y][x] & (1<<d) ) continue;
            
                int next_y=y+dy[d]; int next_x=x+dx[d];
                
                if(check(next_y,next_x)){
                    if(visited[next_y][next_x]==false){
                        //cout<<next_y<<","<<next_x<<"방문"<<endl;
                        room_size++;
                        visited[next_y][next_x]=true;
                        q.push(point(next_y,next_x));
                    }
                }
            
        }
    }
    //cout<<first_y<<","<<first_x<<" 로 부터 시작한 방의 사이즈는 "<<room_size<<endl;
    return room_size;
}



int main(){
    
    cin>>m>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>map[i][j];
        }
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(visited[i][j]==false){
                result2=max(result2,bfs(i,j));
                result1++;
            }
        }
    }
    //비효율적인 것 같은데.....
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            for(int d=0; d<4; d++){
                if(map[i][j]&(1<<d)){
                    int next_y=i+dy[d];
                    int next_x=j+dx[d];
                    if(check(next_y,next_x)){
                        memset(visited,false,55*55);

                        map[i][j]-= (1<<d);
                        result3=max(result3,bfs(i, j));
                        map[i][j]+= (1<<d);
                    }
                }
            }
        }
    }
    
    
    cout<<result1<<endl;
    cout<<result2<<endl;
    cout<<result3<<endl;
    
    return 0;
}

/*
 4 1
 15 15 15 15
 4
 1
 0
 
 5 4
 11 14 7 11 6
 3 14 5 15 5
 5 15 5 3 12
 9 14 13 13 15
 
 7
 6
 10
 
 10 5
 3 10 10 2 10 10 2 10 10 6
 1 6 3 4 3 6 1 6 3 4
 1 4 1 4 1 4 1 4 1 4
 1 12 9 4 9 12 1 12 9 4
 9 10 10 8 10 10 8 10 10 12
 
 2
 44
 50
 
 */
