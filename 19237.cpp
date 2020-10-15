#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
int n, m, k;
struct map{
    vector<int> v;
    int smell_cnt;
    int smell_host;
};
map arr[22][22];

struct shark{
    int y;
    int x;
    int d;
    int dead;
    vector<int> priority[4];
};
shark sharks[444];

int dy[5] = {0, -1, 1, 0, 0};
int dx[5] = {0, 0, 0, -1, 1};

int check(){
    for(int i=2; i<=m; i++){
        if(!sharks[i].dead) return 0;
    }
    return 1;
}

void smell(int time){
    for(int i=1; i<=m; i++){
        if(sharks[i].dead) continue;
        int y = sharks[i].y;
        int x = sharks[i].x;
        arr[y][x].smell_cnt = time + k;
        arr[y][x].smell_host = i;
    }
}
void move(int time){
    for(int i=1; i<=m; i++){
        if(sharks[i].dead) continue;
        int y = sharks[i].y;
        int x = sharks[i].x;
        arr[y][x].v.clear();
    }
    
    for(int i=1; i<=m; i++){
        if(sharks[i].dead) continue;
        int y = sharks[i].y;
        int x = sharks[i].x;
        int d = sharks[i].d;

        int flag=1;
        int ty, tx, td;
        ty=tx=td=-1;
        for(int j=0; j<sharks[i].priority[d].size(); j++){
            int nd = sharks[i].priority[d][j];
            int ny = y + dy[nd];
            int nx = x + dx[nd];
            if(ny<0 || nx<0 || ny>=n || nx>=n) continue;
            if(arr[ny][nx].smell_cnt <= time){
                flag=0;
                arr[ny][nx].v.push_back(i);
                sharks[i].y=y;
                sharks[i].x=x;
                sharks[i].d=nd;
                break;
            }
            else{
                if(arr[ny][nx].smell_host==i){
                    if(ty==-1){
                        ty=nx;
                        tx=nx;
                        td=nd;
                    }
                }
            }
        }
        if(flag){
            arr[ty][tx].v.push_back(i);
            sharks[i].y=ty;
            sharks[i].x=tx;
            sharks[i].d=td;
        }
    }
}
void kill(){
    for(int i=1; i<=m; i++){
        if(sharks[i].dead) continue;

        int y = sharks[i].y;
        int x = sharks[i].x;
        if(arr[y][x].v.size()>1){
            sort(arr[y][x].v.begin(), arr[y][x].v.end());
            for(int j=1; j<arr[y][x].v.size(); j++){
                int slave = arr[y][x].v[j];
                sharks[slave].dead=1;
            }
            arr[y][x].v.erase(arr[y][x].v.begin()+1, arr[y][x].v.end());
            arr[y][x].smell_host=arr[y][x].v[0];
        }
    }
}

void func(){
    for(int t=0; t<1001; t++){
        if(check()){
            cout<<t<<endl;
            return;
        }  
        smell(t);
        move(t);
        kill();
    }
    cout<<-1<<endl;
}


int main(){
    cin>>n>>m>>k;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int a; cin>>a;
            if(a!=0){
                arr[i][j].v.push_back(a);
                sharks[a].y=i;
                sharks[a].x=j;
            }
        }
    }
    for(int i=1; i<=m; i++){
        int a; cin>>a;
        sharks[i].d = a;
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=4; j++){
            for(int k=1; k<=4; k++){
                int a; cin>>a;
                sharks[i].priority[j].push_back(a);
            }
        }
    }
    for(int t=0; t<1001; t++){
        func();
    }



    return 0;
}