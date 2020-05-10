#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <iostream>
#include <tuple>
#include <cstdio>


using namespace std;

int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
int n;
vector<vector<int> > board;

int bfs() {
    priority_queue<pair<pair<int, int>, pair<int, int> > > pq;
    bool visited[30][30][4];
    memset(visited, 0, sizeof(visited));
    // pq.push({{0, -1}, {0, 0}});
    pq.push(make_pair(make_pair(0,-1),make_pair(0,0)));
    
    while(!pq.empty()) {
        int money = -pq.top().first.first;
        int dir = pq.top().first.second;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();
        
        if(visited[y][x][dir]) continue;
        
        if(y==n-1 && x==n-1){
            return money;
        }

        visited[y][x][dir] = true;
        for(int d=0; d<4; d++){
            int ny = y + dy[d];
            int nx = x + dx[d];
            if(ny<0 || nx<0 || ny==n || nx==n) continue;
            if(visited[ny][nx][d]) continue;
            if(board[ny][nx]) continue;

            if(dir == d || dir==-1) {
                // pq.push({{-(money + 100), d}, {ny, nx}});
                pq.push(make_pair(make_pair(-(money+100),d),make_pair(ny,nx)));
                
            } else {
                // pq.push({{-(money + 600), d}, {ny, nx}});
                pq.push(make_pair(make_pair(-(money+600),d),make_pair(ny,nx)));
            }
        }
        
    }
    return 2100000000;
}

int solution(vector<vector<int> > v) {
    n = v.size();
    board = v;
    // int answer = min(bfs(0), bfs(2));
    int answer = bfs();
    return answer;
}

int main(){
    vector<vector<int> > v;
    vector<int> a; a.push_back(0); a.push_back(0); a.push_back(1); a.push_back(0);
    vector<int> b; b.push_back(0); b.push_back(0); b.push_back(0); b.push_back(0);
    vector<int> c; c.push_back(0); c.push_back(1); c.push_back(0); c.push_back(1);
    vector<int> d; d.push_back(1); d.push_back(0); d.push_back(0); d.push_back(0);
    v.push_back(a); v.push_back(b); v.push_back(c); v.push_back(d);
    cout<<solution(v);

    tuple<int, char, double> tu;
    tu = make_tuple(1,'a',3.14);
    return 0;
}