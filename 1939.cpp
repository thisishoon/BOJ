#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int n, m;
int start, finish;
vector< pair<int, int> > v[100001];
int visited[100001];


int bfs(int mid){
    queue<int> q;
    q.push(start);
    visited[start]=1;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        if(cur==finish) return 1;

        for(int i=0; i<v[cur].size(); i++){
            int next = v[cur][i].first;
            int next_cost = v[cur][i].second;
            if(visited[next]==0){
                if(mid<=next_cost){
                    q.push(next);
                    visited[next]=1;
                }
            }
        }
    }
    return 0;
}


int main(){
    scanf("%d %d", &n, &m);
    int left=0; 
    int right=0;
    int mid=0;
    int result=0;
    for(int i=0; i<m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
        
        if(right<c) right=c;
    }
    scanf("%d %d", &start, &finish);
    
    while(left<=right){
        memset(visited, false, sizeof(visited));
        mid=(left+right)/2;
        int flag=bfs(mid);
        if(flag==1) {
            left = mid+1;
            result = mid;
            }
        else{
            right = mid-1;
        }
    }
    printf("%d", result);
    



    return 0;
}