#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> v[100011];
int order[100011];
int arr[100011];
int visited[100011];
vector<int> vv;

int comp(int a, int b){
    return order[a]<order[b];
}

void dfs(int num){
    if(visited[num]==1) return;
    vv.push_back(num);
    visited[num]=1;
    for(int i=0; i<v[num].size(); i++){
        if(visited[v[num][i]]==1){
            continue;
        }
        dfs(v[num][i]);
    }
}
int main(){
    cin>>n;
    for(int i=1; i<n; i++){
        int a, b; cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        cin>>arr[i];
        order[arr[i]]=i;    //트리를 일관된 순서로 바꿔주기위해 저장  
    }
    for(int i=1; i<=n; i++){    //트리의 순서를 정렬 먼저 들어온 것부터
        sort(v[i].begin(), v[i].end(), comp);
    }
    dfs(1);
    int flag=1;
    for(int i=0; i<vv.size(); i++){
        if(vv[i]!=arr[i+1]){
            cout<<"0"<<endl;
            flag=0;
            break;
        }
    }

    if(flag) cout<<"1"<<endl;

    return 0;
}