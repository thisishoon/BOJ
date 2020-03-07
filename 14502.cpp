#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
vector<pair<int, int> > virus;
vector<pair<int, int> > empty;
int n, m;
int arr[10][10];
int visited[10][10];
int result;
void bfs();
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};

int check_safe(){
    int safeArea=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(arr[i][j]==0) safeArea++;
        }
    }
    return safeArea;
}

void backtracking(int index, int count){
    if(count==3){
        // for(int i=1; i<=n; i++){
        //     for(int j=1; j<=n; j++){
        //         if(visited[i][j]==1) cout<<i<<","<<j<<" ";
        //     }
        // }
        int temp[10][10];
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                temp[i][j]=arr[i][j];
            }
        }
        bfs();
        
        result = max(result, check_safe());
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                arr[i][j]=temp[i][j];
            }
        }
        
        // cout<<endl;
        return;
    }
    for(int i=index; i<empty.size(); i++){
        int y = empty[i].first;
        int x = empty[i].second;
        // if(visited[y][x]==1) continue;
        // visited[y][x]=1;
        arr[y][x]=1;
        backtracking(i+1, count+1);
        // visited[y][x]=0;
        arr[y][x]=0;
    }
    return;
}

void bfs(){
    for(int i=0; i<virus.size(); i++){
        queue<pair<int, int> > q;
        q.push(make_pair(virus[i].first, virus[i].second));
        while(!q.empty()){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            for(int d=0; d<4; d++){
                int nextY=y+dy[d];
                int nextX=x+dx[d];
                if(nextX<=0 || nextY<=0 || nextX>m || nextY>n) continue;
                if(arr[nextY][nextX]==1 || arr[nextY][nextX]==2) continue;
                if(arr[nextY][nextX]==0){
                    arr[nextY][nextX]=2;
                    q.push(make_pair(nextY, nextX));
                }
            }
        }
    }
    return;
}


int main(){
    scanf("%d %d", &n, &m);    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d", &arr[i][j]);
            if(arr[i][j]==2) virus.push_back(make_pair(i,j));
            else if(arr[i][j]==0) {
                empty.push_back(make_pair(i, j));}
        }
    }
    backtracking(0, 0);
    cout<<result<<endl;


    return 0;
}