#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
int n, m;
int a1x, a1y, a2x, a2y, b1x, b1y, b2x, b2y;
int result, result2;
int visited[111][111];

int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};

struct node{
    int y, x;
    int count=0;
    vector<pair<int, int> > v;
};
vector<pair<int, int> > trace;


int bfs(int startY, int startX, int endY, int endX, int flag, int yy, int xx, int yyy, int xxx){
   
    node init;
    init.y=startY; init.x=startX;
    init.count=0;
    init.v.push_back(make_pair(startY, startX));
    queue<node> q;
    q.push(init);
    visited[startY][startX]=1;
    while(!q.empty()){
        node cur = q.front();   q.pop();
        if(cur.y==endY && cur.x==endX){ 
            trace = cur.v;
            return cur.count;
        }
    
        for(int d=0; d<4; d++){
            int nextY = cur.y + dy[d]; int nextX = cur.x + dx[d];

            
            if(nextY<0 || nextX<0 || nextY>n || nextX>m) continue;
            if(visited[nextY][nextX]) continue;
            int line=0;
            if(flag==1){
                for(int i=0; i<trace.size(); i++){  //순회하면서 확인
                if(trace[i].first==nextY && trace[i].second==nextX){
                    line=1;
                    continue;
                    }
                }
            }
            if(line==1) continue;
            if(nextY==yy && nextX==xx) continue;
            if(nextY==yyy && nextX==xxx) continue;
            visited[nextY][nextX]=1;
            node next;
            next.y = nextY; next.x = nextX;
            
            if(flag==1){
            vector<pair<int, int> > nextTrace;
            nextTrace.resize((int)cur.v.size());
            copy(cur.v.begin(), cur.v.end(), nextTrace.begin());
            nextTrace.push_back(make_pair(nextY, nextX));
            next.v = nextTrace;
            }
            next.count = cur.count+1;
            q.push(next);

        }
    }
    return 0;
}


int main(){
    cin>>n>>m>>a1y>>a1x>>a2y>>a2x>>b1y>>b1x>>b2y>>b2x;
    int result=0;

    int a = bfs(a1y, a1x, a2y, a2x, 1, b1y, b1x, b2y, b2x);
    memset(visited, 0, sizeof(visited));
    int b =bfs(b1y, b1x, b2y, b2x, 1, a1y, a1x, a2y, a2x);
    if(b==0) result=0;
    else result = a+b;
    
    trace.erase(trace.begin(), trace.end());
    memset(visited, 0, sizeof(visited));
    

    int result2=0;
    
    int c = bfs(b1y, b1x, b2y, b2x, 1, a1y, a1x, a2y, a2x);
   
    memset(visited, 0, sizeof(visited));

    int d = bfs(a1y, a1x, a2y, a2x, 1, b1y, b1x, b2y, b2x);
    
    if(d==0) result2 =0;
    else result2 = c+d;

    if(result==0 && result2==0) cout<<"IMPOSSIBLE"<<endl;
    else if(result==0 && result2!=0) cout<<result2<<endl;
    else if(result!=0 && result2==0) cout<<result<<endl;
    else cout<<min(result, result2)<<endl;
    
    return 0;
}