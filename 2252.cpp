#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
int n, m;
int arr[33333];
int visited[33333];
vector<int> answer;
vector<int> v[33333];

int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        arr[b]++;
        v[a].push_back(b);
    }
    queue<int> q;

    for(int i=1; i<=n; i++){
        if(arr[i]==0){
            q.push(i);
            // visited[i]=1;
        }
    }

    while(!q.empty()){
        int node = q.front();   q.pop();
        printf("%d ", node);

        for(int i=0; i<v[node].size(); i++){
            int parent = v[node][i];
            arr[parent]--;
            if(arr[parent]==0) q.push(parent);
        }
     
    }


    return 0;
}