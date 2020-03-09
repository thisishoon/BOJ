#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
int n;
int arr[22][22];
int visited[22][22];
int result;
int babyshark_size=2;
int eat_size;
int startY, startX;
int dy[4]={1,-1,0,0};
int dx[4]={0,0,-1,1};
vector<pair<int, int> > v;


int bfs(int y, int x){
    memset(visited, 0, sizeof(visited));
    v.erase(v.begin(), v.end());

    queue<pair<int, int> >q;
    q.push(make_pair(y, x));
    visited[y][x]=1;
    int dist = 999999999;
    while(!q.empty()){
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        if(arr[curY][curX]<babyshark_size && arr[curY][curX]>0){ //can eat fish
            if(dist>=visited[curY][curX]-1){
                v.push_back(make_pair(curY, curX));
                dist = visited[curY][curX]-1;
            }
        }
        

        for(int d=0; d<4; d++){
            int nextY=curY + dy[d];
            int nextX=curX + dx[d];
            if(nextY==0 || nextX==0 || nextX>n || nextY>n) continue;
            if(arr[nextY][nextX]>babyshark_size) continue;
            if(visited[nextY][nextX]!=0) continue;

            visited[nextY][nextX] = visited[curY][curX] + 1;
            q.push(make_pair(nextY, nextX));   
        }
    }

    return dist;
}

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &arr[i][j]);
            if(arr[i][j]==9){
                arr[i][j]=0;
                startY=i; startX=j;
            }
        }
    }
    while(1){

        int flag = bfs(startY, startX);
        if(flag==999999999) break;
        else{
            int fishY=33; int fishX=33;
            for(int i=0; i<v.size(); i++){
                int yy = v[i].first; int xx = v[i].second;
                if(fishY>yy){
                    fishY = yy; fishX = xx;
                }
                else if(fishY==yy && fishX>xx){
                    fishX = xx;
                }
            }
            // eat
            // cout<<arr[fishY][fishX]<<" "<<fishY<<" "<<fishX<<endl;
            eat_size++;
            arr[fishY][fishX]=0;
            startY=fishY; startX=fishX;
            result += flag;
            if(eat_size==babyshark_size){
                babyshark_size++;
                eat_size=0;
            }
        }
    }
    printf("%d\n", result);
    return 0;

}