#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int capacity[100][100];
int flow[100][100];
//capacity - flow = residual network
vector<int> v[100];
int S='A'-'A';
int Z='Z'-'A';
int result;

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        char a, b;
        int c;
        cin>>a>>b>>c;
        int q=a-'A';
        int w=b-'A';
        capacity[q][w]+=c;    // a와 b사이의 edge는 유일하지 않음
        capacity[w][q]+=c;
        v[q].push_back(w);
        v[w].push_back(q);
        
    }
    
    while(1){
        int parent[100];
        for(int i=1; i<100; i++){ //1부터 초기화해주는 이유는 노드A로 다시 되돌아가지 않기위해
            parent[i]=-1;
        }
        
        queue<int> q;
        q.push(S);
        
        while(!q.empty()){  //BFS반복
            int now = q.front();
            q.pop();
            
            for(int i=0; i<v[now].size(); i++){
                int next=v[now][i];
                if(capacity[now][next]-flow[now][next] > 0 && parent[next] == -1){ //그래프가 양방향이여서 path를 찾을 땐 순방향으로 찾아야하는걸 주의! 안그러면 계속 돈다 !!
                    q.push(next);
                    parent[next] = now;
                    if(next == Z) break;
                }
            }
        }
        
        if(parent[Z] == -1)  break;   // <종료조건> 더이상 Z까지의 경로를 찾지못할 경우
        
        
        
        int f = 999999999;
        for(int i=Z; i!=S; i=parent[i])
            f = min(f, capacity[parent[i]][i]-flow[parent[i]][i]); //경로를 따라 flow의 최솟값을 구하기
        
        
        for(int i=Z; i!=S; i=parent[i]){
            flow[parent[i]][i] += f;
            flow[i][parent[i]] -= f;
        }
        result += f;
    }
    cout<<result;
    return 0;
}
