#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, m, t;
int mainA, mainB, mainC;
int store;
vector<pair<int, int> > v[100000];
int dist[100000];
int visited[100000];
priority_queue<pair<int, int> > pq;

int dijk(int from){
    pq.push(make_pair(0, from));
    fill(dist, dist+n, 999999999);
    dist[from]=0;
    //fill(visited, visited+n, 0);
    //visited[from]=1;
    while(!pq.empty()){
        int here = pq.top().second;
        int hereCost = -pq.top().first;
        pq.pop();
        
        for(int i=0; i<v[i].size(); i++){
            int next = v[here][i].first;
            int nextCost = v[here][i].second;
            if(dist[next] > dist[here]+nextCost){
                dist[next] = dist[here]+nextCost;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }
    return &dist;
}


int main(){ 
    scanf("%d", &n);
    scanf("%d %d %d", &mainA, &mainB, &mainC);
    scanf("%d", &m);
    for(int i=1; i<=m;i++){
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        v[x].push_back(make_pair(y,z));
        v[y].push_back(make_pair(x,z));
    }
    scanf("%d", &t);
    while(t--){
        scanf("%d", &store);
        int dijk(store, mainA, mainB, mainC);
        

    }
    return 0;
}