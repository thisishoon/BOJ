#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
int n,m;
int arr[55][55];
pair<int, int> virus[11];
vector<pair<int, int> > v;
int answer=999999999;
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};

void spread();

void select(int num, int last){
    if(num>m){
        int temp[55][55];
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                temp[i][j]=arr[i][j];
        spread();
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                arr[i][j]=temp[i][j];

        return;
    } 
    for(int i=last; i<v.size(); i++){
        int y = v[i].first;
        int x = v[i].second;
        virus[num].first=y;
        virus[num].second=x;
        select(num+1, i+1);
    }
}

int check(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(arr[i][j]==0){
                return 0;
            }
        }
    }
    return 1;
}

void spread(){
    int visited[55][55];
    memset(visited, 0, sizeof(visited));

    queue<pair< pair<int, int>, int> > q;
    for(int i=1; i<=m; i++){
        q.push(make_pair( make_pair(virus[i].first, virus[i].second), 0) );
        visited[virus[i].first][virus[i].second]=1;
        // cout<<virus[i].first<<","<<virus[i].second<<" ";
    }
    // cout<<endl;
    int cnt=0;
    while(!q.empty()){
        int y = q.front().first.first;
        int x = q.front().first.second;
        int c = q.front().second;
        q.pop();
        if(cnt<c){
            if(check()){
                answer = min(answer, c);
                return;
            }
            else if(c>answer){
                return;
            }
            cnt=c;
        }

        for(int d=0; d<4; d++){
            int ny = y+dy[d];
            int nx = x+dx[d];
            if(ny==0 || nx==0 || ny>n || nx>n) continue;
            if(visited[ny][nx]==1) continue;
            if(arr[ny][nx]==1) continue;
            visited[ny][nx]=1;
            arr[ny][nx]=2;
            q.push(make_pair(make_pair(ny, nx), c+1));
        }
    }
}


int main(){
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &arr[i][j]);
            if(arr[i][j]==2) v.push_back(make_pair(i, j));
        }
    }
    if(check()){
        cout<<"0"<<endl;
        return 0;
    }
    
    select(1, 0);
    if(answer==999999999) cout<<"-1"<<endl;
    else cout<<answer<<endl;

    return 0;
}