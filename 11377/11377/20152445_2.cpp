#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 2002

using namespace std;

int result, e;
vector<int> v[MAX];
int path[MAX];
bool bfs(){
    int i, k;
    int check[MAX] = { 0 };
    queue<int> q;
    vector<int>::iterator iter;
    q.push(0);
    check[0]=1;
    do{
        k=q.front();
        q.pop();
        for(iter=v[k].begin(); iter!=v[k].end(); iter++){
            if(!check[*iter]){
                path[*iter]=k;
                if(*iter == e) return true;
                check[*iter]=1;
                q.push(*iter);
            }
        }
    }while(!q.empty());
    return false;
}
bool network_flow(){
    bool b;
    int ee, t;
    vector<int>::iterator iter;
    b = bfs();
    if(!b) return false;
    ee=e;
    while(ee>0){
        t=path[ee];
        for(iter=v[t].begin(); iter!=v[t].end(); iter++){
            if(*iter==ee){
                v[t].erase(iter);
                break;
            }
        }
        v[ee].push_back(t);
        ee=t;
    }
    return true;
}
int main(){

    int n, m, k, e;
    cin >> n >> m >> k;
    e=n+m+1;
    for(int i=1; i<=n; i++){
        int c;
        cin >> c;
        for(int j=0; j<c; j++){
            int t;
            cin >> t;
            v[i].push_back(n+t);
        }
        v[0].push_back(i);
    }
    
    for(int i=1; i<=m; i++) v[n+i].push_back(e);
    
    while(network_flow()) result++;
    
    for(int i=1; i<=n; i++) v[0].push_back(i);
    while(k>0 && network_flow()) result++, k--;
    cout << result;
    return 0;
}
