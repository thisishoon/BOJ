#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;
int arr[4][4];
int sum;
struct st{
    int cnt;    //조작 횟수 
    int num;    //짝을 맞춘 횟수 num==sum이 되면 끝
    int pre;  //초기값 = 0, enter를 누르고 가지고 있던 번호 저장
    int y;
    int x;
    int ar[4][4];
};
int visited[4][4];
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};

int bfs(int r, int c){
    queue<st> q;
    visited[r][c]=1;
    int temp[4][4];
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            temp[i][j] = arr[i][j];

    q.push({0, 0, 0, r, c, temp});
    
    while(!q.empty()){
        int cnt = q.front().cnt;
        int num = q.front().num;
        int pre = q.front().pre;
        int y = q.front().y;
        int x = q.front().x;
        int arr[4][4];
        for(int i=0; i<4; i++)
            for(int j=0; j<4; j++)
                arr[i][j] = q.front().ar[i][j];


        q.pop();
        cout<<cnt<<" "<<num<<" "<<pre<<" "<<y<<" "<<x<<endl;
        if(num==sum){
            return cnt;
        }
        
        for(int d=0; d<4; d++){
            int ny = y + dy[d];
            int nx = x + dx[d];
            if(ny<0 || ny==4 || nx<0 || nx==4) continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx]=1;
            q.push({cnt+1, num, pre, ny, nx, &arr});
            // cout<<cnt+1<<" "<<num<<" "<<pre<<" "<<ny<<" "<<nx<<endl;
        }

        for(int d=0; d<4; d++){
            int ny = y;
            int nx = x;
            while(1){
                ny += dy[d]; nx += dx[d];
                if(ny<0 || ny==4 || nx<0 || nx==4){
                    ny -= dy[d]; nx -= dx[d];
                    break;
                }
                if(arr[ny][nx]) break;
            }

            if(ny==y && nx==x) continue;
            if(visited[ny][nx]) continue;
            // cout<<cnt+1<<" "<<num<<" "<<pre<<" "<<ny<<" "<<nx<<endl;
            q.push({cnt+1, num, pre, ny, nx, &arr});
            visited[ny][nx]=1;
        }

        if(arr[y][x]==100) continue;

        if(pre==0){
            if(arr[y][x]){
                // cout<<cnt+1<<" "<<num<<" "<<arr[y][x]<<" "<<y<<" "<<x<<endl;
                arr[y][x]=100;
                visited[y][x]=1;
                q.push({cnt+1, num, arr[y][x], y, x, &arr});
            }
        }
        else{
            if(arr[y][x] == pre){
                arr[y][x]=0;
                for(int i=0; i<4; i++){
                    for(int j=0; j<4; j++){
                        if(arr[i][j]==100) arr[i][j]=0;
                    }
                }
                q.push({cnt+1, num, arr[y][x], y, x, &arr});
            }
        }
        
        
    }
    
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 0;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            arr[i][j] = board[i][j];
            if(arr[i][j]!=0) sum++;
        }
    }
    sum/=2;    
    answer = bfs(r,c);
    return answer;
}

int main(){
    vector<vector<int> > board = {{1,0,0,3}, {2,0,0,0}, {0,0,0,2}, {3,0,1,0}};
    int r = 1;
    int c = 0;
    solution(board, r, c);
}