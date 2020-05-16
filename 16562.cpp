#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m, k;
int arr[10011];
int parent[10011];
int answer;
int visited[10011];

int find(int x){
    if(parent[x]==x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b){
    int x = find(a);
    int y = find(b);
    if(x==y) return;
    if(arr[x]<arr[y]) parent[y] = x;
    else parent[x]=y;
    return;
}

int main(){

    cin>>n>>m>>k;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    for(int i=1; i<=n; i++){
        parent[i] = i;
    }

    for(int i=1; i<=m; i++){
        int a, b;
        cin>>a>>b;
        merge(a,b);
    }
    for(int i=1; i<=n; i++){
        if(visited[find(i)]==1) continue;
        answer += arr[find(i)];
        visited[find(i)]=1;
    }
    //cout<<answer<<endl;

    if(answer<=k) cout<<answer<<endl;
    else cout<<"Oh no"<<endl;


    return 0;
}