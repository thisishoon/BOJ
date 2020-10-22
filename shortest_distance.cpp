#include <iostream>
#include <queue>

using namespace std;

int arr[111][111];
int n;
int distance[111][111];

void floyd(){
    // i -> i : 0
    // i -> j (if i and j is connected) : arr[i][j]
    // else infinite
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(distance[j][k] > distance[j][i] + distance[i][k]){
                    distance[j][k] = distance[j][i] + distance[i][k];
                }
            }
        }
    }
}

//음의 간선 가능
void bellman(int start, int n, vector<int< arr[]){
    int dist[111];
    cosnt int INF = 2100000000;
    memset(dist, INF, sizeof(dist));
    dist[start] = 0;    
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n; j++){
            for(auto p : adj[j]){
                int next = i.first;
                int cost = i.second;
                if(dist[j]!=INF && dist[next] > dist[j] + cost){
                    dist[next] = dist[j] + cist;
                }
            }
        }
    }
}


void dijk(int start, int n){
    int dist[111];
    int visited[111];
    cosnt int INF = 2100000000;
    memset(dist, INF, sizeof(dist));
    memset(visited, 0, sizeof(visited));
    dist[start] = 0;    

    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, start));
    whiel(!pq.empty()){
        int cost = -pq.top().first;
        int next = pq.top().second;
        pq.pop();
        for(int i=0; i<adj[next].size(); i++){
            int next = adj[next][i].first;
            int next_weight = adj[next][i].second;
            if(cost + next_weight<dist[next]){
                dist[next] = cost + next_weight;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }

    
    
}





int main(){
    
    return 0;
}