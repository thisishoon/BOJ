#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <string.h>
#include <queue>

using namespace std;
int arr[7][7];
int visited[7][7];
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int flag;

void bfs(int i, int j){
    queue<pair<int, int> > q;
    q.push(make_pair(i,j));
    visited[i][j]=1;
    int color = arr[i][j];
    vector<pair<int, int> > v;
    v.push_back(make_pair(i,j));
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int d=0; d<4; d++){
            int ny = y + dy[d];
            int nx = x + dx[d];
            if(ny==0 || ny==7 || nx==0 || nx==7) continue;
            if(visited[ny][nx]==1) continue;
            if(arr[ny][nx]!=color) continue;
            visited[ny][nx]=1;
            q.push(make_pair(ny,nx));
            v.push_back(make_pair(ny,nx));
        }
    }
    if(v.size()>=3){
        flag=1;
        for(int i=0; i<v.size(); i++){
            arr[v[i].first][v[i].second]=0;
        }
    }
}

bool boom(){
    memset(visited, 0, sizeof(visited));
    flag=0;
    for(int i=1; i<=6; i++){
        for(int j=1; j<=6; j++){
            if(visited[i][j]==0 && arr[i][j]!=0){
                bfs(i, j);
            }
        }
    }
    
    for(int j=1; j<=6; j++){
        vector<int> temp;
        for(int i=6; i>=1; i--){
            if(arr[i][j]!=0) temp.push_back(arr[i][j]);
        }

        for(int i=0; i<temp.size(); i++){
            arr[6-i][j]=temp[i];
        }
        for(int i=temp.size(); i<=6; i++){
            arr[6-i][j]=0;
        }

    }

    return flag;
}

vector<string> solution(vector<vector<int> > macaron){
    for(int m=0; m<macaron.size(); m++){
        int idx = macaron[m][0];
        int color = macaron[m][1];
        for(int i=6; i>=1; i--){
            if(arr[i][idx]==0){
                arr[i][idx]=color;
                break;
            }    
        }
        while(boom()){};
    }
    
    vector<string> result;
    for(int i=1; i<=6; i++){
        string temp = "";
        for(int j=1; j<=6; j++){
            temp += to_string(arr[i][j]);
        }
        result.push_back(temp);
    }
    return result;
}

int main(){
    vector<vector<int> > maca;
    vector<int> v; 
    v.push_back(1); v.push_back(1); maca.push_back(v); v.clear();
    v.push_back(2); v.push_back(1); maca.push_back(v); v.clear();
    v.push_back(1); v.push_back(2); maca.push_back(v); v.clear();
    v.push_back(3); v.push_back(3); maca.push_back(v); v.clear();
    v.push_back(6); v.push_back(4); maca.push_back(v); v.clear();
    v.push_back(3); v.push_back(1); maca.push_back(v); v.clear();
    v.push_back(3); v.push_back(3); maca.push_back(v); v.clear();
    v.push_back(3); v.push_back(3); maca.push_back(v); v.clear();
    v.push_back(3); v.push_back(4); maca.push_back(v); v.clear();
    v.push_back(2); v.push_back(1); maca.push_back(v); v.clear();
    // v.push_back(1); v.push_back(1); maca.push_back(v); v.clear();
    // v.push_back(1); v.push_back(2); maca.push_back(v); v.clear();
    // v.push_back(1); v.push_back(4); maca.push_back(v); v.clear();
    // v.push_back(2); v.push_back(1); maca.push_back(v); v.clear();
    // v.push_back(2); v.push_back(2); maca.push_back(v); v.clear();
    // v.push_back(2); v.push_back(3); maca.push_back(v); v.clear();
    // v.push_back(3); v.push_back(4); maca.push_back(v); v.clear();
    // v.push_back(3); v.push_back(1); maca.push_back(v); v.clear();
    // v.push_back(3); v.push_back(2); maca.push_back(v); v.clear();
    // v.push_back(3); v.push_back(3); maca.push_back(v); v.clear();
    // v.push_back(3); v.push_back(4); maca.push_back(v); v.clear();
    // v.push_back(4); v.push_back(4); maca.push_back(v); v.clear();
    // v.push_back(4); v.push_back(3); maca.push_back(v); v.clear();
    // v.push_back(5); v.push_back(4); maca.push_back(v); v.clear();
    // v.push_back(6); v.push_back(1); maca.push_back(v); v.clear();

    vector<string> answer = solution(maca);
    for(int i=0; i<answer.size(); i++){
        cout<<answer[i]<<endl;
    }
    return 0;
}