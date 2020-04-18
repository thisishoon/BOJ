#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;
int n, e;
vector<pair<int, int> > v[808];
priority_queue<pair<int, int> > pq;
int dist[808];

int dijkstra(int from, int end){
    fill_n(dist, 808, 800000);
    dist[from]=0;
    pq.push(make_pair(0, from));

    while(!pq.empty()){
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        for(int i=0; i<v[here].size(); i++){
            int next = v[here][i].first;
            int next_cost = v[here][i].second;

            if(dist[next] > dist[here] + next_cost){
                dist[next] = dist[here] + next_cost;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }
    return dist[end];
}

int main(){
    cin>>n>>e;
    for(int i=0; i<e; i++){
        int a, b, c;
        cin>>a>>b>>c;
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }
    int mid1, mid2;
    cin>>mid1>>mid2;

    int one_mid1 = dijkstra(1, mid1);
    int one_mid2 = dijkstra(1, mid2);
    int mid1_mid2 = dijkstra(mid1, mid2);
    int mid1_end = dijkstra(mid1, n);
    int mid2_end = dijkstra(mid2, n);
    //cout<<one_mid1<<"->"<<mid1_mid2<<"->"<<mid2_end<<endl;
    //cout<<one_mid2<<"->"<<mid1_mid2<<"->"<<mid1_end<<endl;
    
    int result = 999999999;
    result = min( (one_mid1+mid1_mid2+mid2_end), (one_mid2+mid1_mid2+mid1_end));

    if(result>=800000){
        cout<<"-1"<<endl;
        return 0;
    }
    cout<<result<<endl;
    return 0;
}