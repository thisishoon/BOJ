#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
int n, k;
vector<int> v[15][15];  //말 번호, 방향
int arr[15][15];
pair<pair<int, int>, int> horse[15];

int dy[5]={0,0,0,-1,1};
int dx[5]={0,1,-1,0,0};
int answer=0;

void prin(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(v[i][j].size()==0) cout<<"x";
            for(int k=0; k<v[i][j].size(); k++){
                cout<<v[i][j][k]<<"(" << horse[v[i][j][k]].second<<")";
            }
            cout<<" ";
        }
        cout<<endl;
    }
    cout<<"--------------------------"<<endl;
}

int findIdx(int y, int x, int num){
    for(int i=0; i<v[y][x].size(); i++){
        int idx = v[y][x][i];
        if(idx==num){
            return i;
        }
    }
    return -1;
}

int check(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(v[i][j].size()>=4) return 1;
        }
    }
    return 0;
}

int func(){
    for(int num=1; num<=k; num++){
        int y = horse[num].first.first;
        int x = horse[num].first.second;
        int d = horse[num].second;
        int idx = findIdx(y,x,num);
        int ny = y+dy[d];
        int nx = x+dx[d];
        if(arr[ny][nx]==2 || ny==0 || nx==0 || ny>n || nx>n){
            if(d%2==0) d--;
            else d++;
            ny = y+dy[d];
            nx = x+dx[d];
            horse[num].second=d;
        }

        if(arr[ny][nx]==0){ //하양
            for(int i=idx; i<v[y][x].size(); i++){  //
                int index = v[y][x][i];
                v[ny][nx].push_back(index);
                horse[index].first.first=ny;
                horse[index].first.second=nx;
                
            }
            v[y][x].erase(v[y][x].begin()+idx, v[y][x].end());
        }

        else if(arr[ny][nx]==1){    //빨강
            for(int i=v[y][x].size()-1; i>=idx; i--){
                int index = v[y][x][i];
                v[ny][nx].push_back(index);
                horse[index].first.first=ny;
                horse[index].first.second=nx;
            }
            v[y][x].erase(v[y][x].begin()+idx, v[y][x].end());
        }

        if(check()) return 1;
    }
    return 0;
}

int main(){
    cin>>n>>k;
    memset(arr, -1, sizeof(arr));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
        }
    }
    for(int i=1; i<=k; i++){
        int a, b, c;
        cin>>a>>b>>c;
        horse[i].first.first=a;
        horse[i].first.second=b;
        horse[i].second=c;
        v[a][b].push_back(i);
    }

    if(check()){
        cout<<answer<<endl;
        return 0;
    }


    while(1){
        answer++;
        if(func()){
            cout<<answer<<endl;
            return 0;
        }
        
        if(answer>1000){
            cout<<"-1"<<endl;
            return 0;
        }
    }

    return 0;
}