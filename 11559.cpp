#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;
char arr[12][6];
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int visited[12][6];
int answer=-1;
int flag;

void bfs(int i, int j){
    visited[i][j]=1;
    queue<pair<int, int> > q;
    vector<pair<int, int> > v;
    char color = arr[i][j];
    q.push(make_pair(i,j));
    v.push_back(make_pair(i, j));
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int d=0; d<4; d++){
            int ny = y + dy[d];
            int nx = x + dx[d];
            if(ny<0 || ny>=12 || nx<0 || nx>=6) continue;
            if(visited[ny][nx]) continue;
            if(arr[ny][nx]!=color) continue;
            visited[ny][nx]=1;
            q.push(make_pair(ny, nx));
            v.push_back(make_pair(ny, nx));
        }
    }
    if(v.size()>=4){
        flag=1;
        for(int i=0; i<v.size(); i++){
            arr[v[i].first][v[i].second]='.';
        }
    }
}
bool boom(){
    memset(visited, 0, sizeof(visited));
    answer++;
    flag=0;
    for(int i=0; i<12; i++){
        for(int j=0; j<6; j++){
            if(visited[i][j]==0 && arr[i][j]!='.'){
                bfs(i, j);
            }
        }
    }

    for(int j=0; j<6; j++){
        for(int i=10; i>=0; i--){
            for(int k=11; k>i; k--){
                if(arr[k][j]=='.'){
                    arr[k][j]=arr[i][j];
                    arr[i][j]='.';
                    break;
                }
            }
        }
    }

    // for(int j=0; j<6; j++){
    //     vector<char> temp;
    //     for(int i=11; i>=0; i--){
    //         if(arr[i][j]!='.'){
    //             temp.push_back(arr[i][j]);
    //         }
    //     }
    //     for(int i=0; i<temp.size(); i++){
    //         arr[11-i][j]=temp[i];
    //     }
    //     for(int i=temp.size(); i<12; i++){
    //         arr[11-i][j]='.';
    //     }
    // }
    return flag;
}

int main(){
    for(int i=0; i<12; i++){
        for(int j=0; j<6; j++){
            char c; cin>>c;
            arr[i][j]=c;
        }
    }
    while(boom()){};
    
    cout<<answer<<endl;


    return 0;
}