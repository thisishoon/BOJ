#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;
int answer = INT32_MAX;
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int visited[30][30][4];
int n;


int solution(vector<vector<int>> v) {
    n = v.size();
    priority_queue<pair<pair<int, int>, pair<int, int> > > pq;
    pq.push({ {0, 0}, {0,0} });
    pq.push({ {0, 2}, {0,0} });
    

    while(!pq.empty()){
        int money = - pq.top().first.first;
        int dir = pq.top().first.second;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();
        cout<<y<<" "<<x<<endl;
        
        if(visited[y][x][dir]==1) continue;
        visited[y][x][dir]=1;

        if(y==n-1 && x==n-1){
            return money;
        }

        for(int d=0; d<4; d++){
            int ny = y+dy[d];
            int nx = x+dx[d];
            if(ny==0 && nx==0) continue;
            if(ny<0 || nx<0 || ny>=n || nx>=n) continue;
            if(v[ny][nx]==1) continue;
            if(visited[ny][nx][d]==1) continue;
            if(dir != d) pq.push({ {-(money+600),d}, {ny,nx} });
            else pq.push({ {-(money+100),d},{ny,nx}});
        }

    }
    return answer;
}

int main(){
    vector<vector<int> > v;
    vector<int> temp1;
    temp1.push_back(0);
    temp1.push_back(0);
    temp1.push_back(1);
    temp1.push_back(0);
    vector<int> temp2;
    temp2.push_back(0);
    temp2.push_back(0);
    temp2.push_back(0);
    temp2.push_back(0);
    vector<int> temp3;
    temp3.push_back(0);
    temp3.push_back(1);
    temp3.push_back(0);
    temp3.push_back(1);
    vector<int> temp4;
    temp4.push_back(1);
    temp4.push_back(0);
    temp4.push_back(0);
    temp4.push_back(0);
    v.push_back(temp1);
    v.push_back(temp2);
    v.push_back(temp3);
    v.push_back(temp4);

    cout<<solution(v)<<endl;


    return 0;
}