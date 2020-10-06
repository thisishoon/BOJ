#include <iostream>
#include <cmath>

using namespace std;
int k;
int arr[1100];
int visited[1100];
int result[1100];
int l, r;
int position=1;

void dfs(int cur){
    if(!visited[cur*2] && cur<l) dfs(cur*2);

    // if(!visited[cur] && l <= cur && cur <= r){
    //     visited[cur]=1;
    //     result[cur] = arr[position++];
    // }
    // if(!visited[cur]&&visited[cur*2]){
    //     visited[cur]=1;
    //     result[cur] = arr[position++];
    // }

    if(!visited[cur]){
        visited[cur]=1;
        result[cur]=arr[position++];
    }

    if(!visited[cur*2+1] && cur<l){
        dfs(cur*2+1);
    }
}

int main(){
    cin>>k;
    for(int i=1; i<pow(2,k); i++){
        cin>>arr[i];
    }
    l = pow(2,k-1);
    r = pow(2,k)-1;

    dfs(1);

    int pos=1;
    for(int i=0; i<k; i++){
        for(int j=0; j<pow(2,i); j++){
            cout<<result[pos++]<<" ";
        }
        cout<<endl;
    }

    return 0;
}