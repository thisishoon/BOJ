#include <iostream>
#include <algorithm>

using namespace std;
int n;
int arr[100001];
int visited[100001];
int done[100001];
int answer;

void dfs(int num){
    // cout<<num<<"@";
    visited[num]=1;
    if(visited[arr[num]]==0){  //내가 원하는 친구가 방문 한 적이 있다
        dfs(arr[num]);
    }
    else if(done[arr[num]]==0){ //사이클을 찾았다
        answer++;
        for(int i=arr[num]; i!=num; i=arr[i]){
            answer++;
        }
    }
    done[num]++;    
    
}


int main(){
    int t; scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i=1; i<=n; i++){
            scanf("%d", &arr[i]);
        }
        for(int i=1; i<=n; i++){
            if(visited[i]) continue;
            dfs(i);
        }
        cout<<n-answer<<endl;
        answer=0;
        for(int i=1; i<=n; i++){
            visited[i]=0;
            done[i]=0;
        }

    }

    return 0;
}