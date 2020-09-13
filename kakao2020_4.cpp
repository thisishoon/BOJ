#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <string>

using namespace std;
// int arr[202][202];
vector<pair<int, int> > v[202];

int dist[202][202];

int N;

void bfs(int start){
    int temp[202];
    int visited[202];
    fill(temp+1, temp+1+N, 999999999);
    fill(visited+1, visited+1+N, 0);
    priority_queue<pair<int, int> > pq;
    pq.push({0, start});
    temp[start]=0;

    while(!pq.empty()){
        int now;
        do{
            now = pq.top().second;
            pq.pop();
        }while(!pq.empty() && visited[now]);
        if(visited[now]) break;
        visited[now]=1;
        
        for(int i=0; i<v[now].size(); i++){
            int next = v[now][i].first;
            int nextCost = v[now][i].second;
            if(visited[next]) continue;
            if(temp[next] > temp[now]+nextCost){
                temp[next] = temp[now] + nextCost;
                pq.push({-temp[next], next});
            }
        }



    }
    for(int i=1; i<=N; i++){
        if(dist[start][i]==0 || dist[start][i] > temp[i]) dist[start][i] = temp[i];
    }
    
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 2100000000;
    N=n;
    for(int i=0; i<fares.size(); i++){
        // arr[fares[i][0]][fares[i][1]] = fares[i][2];
        // arr[fares[i][1]][fares[i][0]] = fares[i][2];
        int first = fares[i][0];
        int second = fares[i][1];
        int cost = fares[i][2];
        v[first].push_back({second, cost});
        v[second].push_back({first, cost});
        
    }
    for(int i=1; i<=n; i++) bfs(i);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    
    for(int i=1; i<=n; i++){
        if(dist[s][i]==999999999) continue;
        if(dist[i][a]==999999999) continue;
        if(dist[i][b]==999999999) continue;
        int cost = dist[s][i] + dist[i][a] + dist[i][b];
        answer = min(answer, cost);
    }
    cout<<answer<<endl;

    return answer;
}

int main(){
    int n = 7;
    int s = 3;
    int a = 4;
    int b = 1;
    vector<vector<int>> fares = {{5, 7, 9}, {4, 6, 4}, {3, 6, 1}, {3, 2, 3}, {2, 1, 6}};
    // vector<vector<int>> fares = {{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}};
    solution(n, s, a, b, fares);
}