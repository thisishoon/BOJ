#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <stack>
using namespace std;

int visited[10001];
int parent[10001];
char d[4]={'D', 'S', 'L', 'R'};

void bfs(int a, int b){
    memset(visited, 0, sizeof(visited));
    memset(parent, 0, sizeof(parent));

    queue<int> q;
    q.push(a);
    visited[a]=1;
    parent[a]=-1;

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        if(cur==b){
            stack<char> s;

            while(parent[cur]!=-1){
                s.push(visited[cur]);
                cur = parent[cur];
            }
            while(!s.empty()){
                printf("%c", s.top());
                s.pop();
            }

            return;
        }
        
        for(int i=0; i<4; i++){
        int next=0;
        if(i==0){
            next = (cur*2)%10000;
        }
        else if(i==1){
            if(cur==0) next = 9999;
            else next = cur-1;
        }
        else if(i==2){
            next = (cur%1000)*10 + cur/1000;
        }
        else{
            next = cur/10+ (cur%10)*1000;
        }
        
        if(visited[next]!=0) continue;
        //if(next<0 || next>=10000) continue;
        visited[next]=d[i];
        parent[next]=cur;
        q.push(next);
        }
    }
}


int main(){
    int t; scanf("%d", &t);
    while(t--){
        int a, b;
        scanf("%d %d", &a, &b);
        bfs(a,b);
        printf("\n");
    }
    return 0;
}