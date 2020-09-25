#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
int n, m;
int arr[33000];
vector<int> v[33000];

int main(){
    cin>>n>>m;
    priority_queue<int> pq;

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        arr[b]++;
        v[a].push_back(b);
    }
    for(int i=1; i<=n; i++) if(!arr[i]) pq.push(-i);

    while(!pq.empty()){
        int cur = -pq.top(); pq.pop();
        cout<<cur<<" ";

        for(int next : v[cur]){
            if(!--arr[next]) pq.push(-next);
        }
    }


    return 0;
}