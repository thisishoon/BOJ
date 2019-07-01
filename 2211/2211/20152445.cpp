#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
#define INF 999999999
int n,m;
vector<pair<int,int>> v[1001];
priority_queue<pair<int,int>> pq;   //비용,노드번호

struct node{
    int parent;
    int cost;
};

node node[1001];

int main(){
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int source,dest, cost;
        cin>>source>>dest>>cost;
        v[source].push_back({dest,cost});
        v[dest].push_back({source,cost});
    }
    for(int i=1; i<=n; i++){
        node[i].cost=INF;
    }
    
    node[1].cost=0;
    node[1].parent=1;
    
    pq.push({node[1].cost,1});
    
    while(!pq.empty()){
        
        int cur=pq.top().second;
        int cur_cost=-pq.top().first;
        pq.pop();
        if(node[cur].cost<cur_cost) continue;
        
        for(int i=0; i<v[cur].size(); i++){
            int next=v[cur][i].first;
            int next_cost=cur_cost+v[cur][i].second;
            
            if(node[next].cost>next_cost){
                
                node[next].cost=next_cost;
                node[next].parent=cur;
                pq.push({-next_cost,next});
            }
            
        }
    }
    cout<<n-1<<endl;
    for(int i=2; i<=n; i++){
        cout<<node[i].parent<<" "<<i<<endl;
    }
    return 0;
}
