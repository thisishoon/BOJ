#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
int n,m,s,t;
int scc_number;
int scc[11111],sum[11111],result[11111];
vector<int> input[11111], scc_input[11111], reverse_input[11111];
stack<int> topol;
bool check[11111];

void DFS(int node){
    if(check[node]) return;
    check[node]=true;
    for(int i=0;i<input[node].size();i++){
        int nextNode=input[node][i];
        if(!check[nextNode]) DFS(nextNode);
    }
    topol.push(node);
}
void REVERSE_DFS(int node){
    if(check[node]) return;
    check[node]=true;
    for(int i=0; i<reverse_input[node].size(); i++){
        int nextNode=reverse_input[node][i];
        if(!check[nextNode]) REVERSE_DFS(nextNode);
    }
    sum[scc_number]++;
    scc[node]=scc_number;
}


int main(){
    cin>>n>>m>>s>>t;
    for(int i=1; i<=m; i++){
        int from, to;
        cin>>from>>to;
        input[from].push_back(to);
        reverse_input[to].push_back(from);
    }
    for(int i=1; i<=n; i++){
        if(!check[i]) DFS(i);
    }
    memset(check,false,sizeof(check));
    while(!topol.empty()){
        int temp=topol.top();
        topol.pop();
        if(!check[temp]) {
            REVERSE_DFS(temp);
            scc_number++;
        }
    }
    memset(check,false,sizeof(check));
    
    for(int i =1; i <=n;i++){
        for(int j=0; j<input[i].size(); j++){
            if(scc[i] !=scc[input[i][j]]){
                scc_input[scc[i]].push_back(scc[input[i][j]]);
            }
        }
    }
    int s_group=scc[s];
    int t_gruop=scc[t];
    result[s_group] = sum[s_group];
    queue<int> scc_queue;
    scc_queue.push(scc[s]);
    
    while(!scc_queue.empty()){
        int cur = scc_queue.front();
        scc_queue.pop();
        for(int next=0; next<scc_input[cur].size(); next++){
            if(result[scc_input[cur][next]] < sum[scc_input[cur][next]] + result[cur]) {
                result[scc_input[cur][next]] = result[cur] + sum[scc_input[cur][next]];
                scc_queue.push(scc_input[cur][next]);
            }
        }
    }
    cout<<result[t_gruop]<<endl;
    return 0;
}

