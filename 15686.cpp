#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int n, m;
int arr[55][55];
int visited[55][55];
int dy[4]={1, -1, 0, 0};
int dx[4]={0, 0, 1, -1};
int answer=999999999;
vector<pair<int, int> > house;
vector<pair<int, int> > ch;
vector<pair<int, int> > realch;
int numch;

int BFS(int i, int j){
    memset(visited, 0, sizeof(visited));
    queue <pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(i,j), 0));
    while(!q.empty()){
        int y = q.front().first.first;
        int x = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        if(arr[y][x]==3){
            return cnt;
        }
        for(int d=0; d<4; d++){
            int nextY = y+ dy[d];
            int nextX = x+ dx[d];
            if(nextY==0 || nextX==0 || nextY>n || nextX>n) continue;
            if(visited[nextY][nextX]==1) continue;
            visited[nextY][nextX]=1;
            q.push(make_pair(make_pair(nextY, nextX), cnt+1));
        }
    }
}

int distance(){
    int result = 0;
    for(int i=0; i<house.size(); i++){
        int temp = 999999999;
        for(int j=0; j<realch.size(); j++){
            temp = min(temp, abs(house[i].first-realch[j].first) + 
            abs(house[i].second - realch[j].second));
        }
        result += temp;
    }
    return result;
}

void select(int num, int last){
    if(num==m){
        int result = distance();
        answer = min(result, answer);
        return;
    }
    for(int i=last; i<ch.size(); i++){
        int chY = ch[i].first;
        int chX = ch[i].second;
        arr[chY][chX]=3;
        realch.push_back(make_pair(chY, chX));
        select(num+1, i+1);
        arr[chY][chX]=2;
        realch.pop_back();
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &arr[i][j]);
            if(arr[i][j]==1) house.push_back(make_pair(i,j));
            else if(arr[i][j]==2) ch.push_back(make_pair(i,j));
        }
    }
    select(0,0);
    printf("%d", answer);


    return 0;
}