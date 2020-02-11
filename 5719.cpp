#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int> > vec[505];
priority_queue<pair<int, int> > pq;
int dist[505];
int visited[505];

int dijk(int from, int to){
    fill_n(dist, 505, 999999999);
    pq.push(make_pair(0, from));
    dist[from]=0;
    while(!pq.empty()){
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        for(int i=0; i<vec[here].size(); i++){
            int next = vec[here][i].first;
            int next_cost = vec[here][i].second;
            if(dist[next] > dist[here] + next_cost){
                dist[next] = dist[here] + next_cost;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }
    return 0;
}

int BFS(int from, int to){
    queue<int> q;
    q.push(from);
    while(!q.empty()){
        int here = q.front();
        q.pop();
    }

}



int main(){
    while(1){
        int n, m;
        cin>>n>>m;
        if(n==0 && m==0) break;
        int s, d;
        cin>>s>>d;
        for(int i=0; i<m; i++){
            int u, v, p;
            cin>>u>>v>>p;
            vec[u].push_back(make_pair(v,p));
            vec[v].push_back(make_pair(u,p));
        }
        dijk(s, d);
        


    }
    return 0;
}