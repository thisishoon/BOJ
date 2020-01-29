#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int m, n, k;
int result;
int arr[51][51];
int visited[51][51];
struct point{
    int x;
    int y;
}p;
vector<point> baechu;
queue<point> q;
int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};

void bfs(){
    result++;
    while(!q.empty()){
        point pnt = q.front();
        for(int i=0; i<4; i++){
            int nx=pnt.x+dx[i];
            int ny=pnt.y+dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(visited[ny][nx]==0){
                if(arr[ny][nx]==1){
                    visited[ny][nx]=1;
                    point next;
                    next.y = ny; next.x = nx;
                    q.push(next);
                }
            }
        }
    }
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d", &m, &n, &k);
        for(int i=0; i<k; i++){
            int a, b;
            cin>>a>>b;
            arr[a][b]=1;
            point bb;
            bb.y=a; bb.x=b;
            baechu.push_back(bb);
        }
        cout<<"test";
        for(int i=0; i<baechu.size(); i++){
            point temp = baechu[i];
            if(visited[temp.x][temp.y]==0){
                visited[temp.x][temp.y]=1;
                q.push(temp);
                bfs();
            } 
        }
        printf("%d\n", result);
        
        for(int i=0; i<50; i++){
            for(int j=0; j<50; j++){
                arr[i][j]=0; visited[i][j]=0;
            }
        }
        baechu.clear();
    }
    return 0;
}