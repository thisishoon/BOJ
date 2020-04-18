#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;
int n, k;
int result;
int visited[100111];

void BFS(int subin){
    queue<pair<int, int > > q;
    q.push(make_pair(subin, 0));
    visited[subin] = 1;

    while(!q.empty()){
        int state = q.front().first;
        int num = q.front().second;
        q.pop();
        if(state == k){
            cout<<num<<endl;
            return;
        }
        else{
            if(state-1>=0 && visited[state-1]==0){
                q.push(make_pair(state-1, num+1));
                visited[state-1]=1;
            }
            if(state+1 <= 100000 && visited[state+1]==0){
                q.push(make_pair(state+1, num+1));
                visited[state+1]=1;
            }
            if(state*2 <= 100000 && visited[state*2]==0){
                visited[state*2]=1;
                q.push(make_pair(state*2, num+1));
            }
        }
    }
}

int main(){
    cin>>n>>k;
    BFS(n);
    return 0;
}