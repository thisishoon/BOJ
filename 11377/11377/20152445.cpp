#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

vector<int> edge[1010]; //그래프
bool visited[1010]; //사람
int work[1010];   //일
int result;

int dfs(int now){
    visited[now]=true;
    
    for(int i=0; i<edge[now].size(); i++){
        int next=edge[now][i];
        int next_person=work[next];
        
        if(!visited[next_person]){ //방문한 적이 없다면 방문하려는 노드를 아무도 방문핮않았더라면
            if(!next_person || dfs(next_person)){ //next_person이 존재한다면 재귀 bfs
                    work[next]=now;
                    return 1;  //할 수 있는 일이 있는 경우
            }
        }
    }
    return 0; //할 수 있는 일이 없는 경우
}

int main(){
    int n, m, k;
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++){
        int a;
        cin>>a;
        for(int j=0; j<a; j++){
            int num;
            cin>>num;
            edge[i].push_back(num);
        }
    }
    
    for(int i=1; i<=n; i++){   //먼저 1사람당 1개씩 일을 처리한다
        memset(visited,0,sizeof(visited));
        if(dfs(i)) result++;
    }
    
    for(int i=1; i<=n; i++){    //일을 2개할 수 있는 사람은 2개를 처리한다
        if(k==0) break;
        memset(visited,0,sizeof(visited));
        if(dfs(i)){
            result++;
            k--;
        }
    }
    
    cout<<result<<endl;
    
    return 0;
}
