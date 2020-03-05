#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

char arr[55][55];
int visited[55][55][2];
int n;
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int firstY, firstX, firstStatus;
int endY, endX, endStatus;

struct tree{
    int y;
    int x;
    int status;
    int count;
};

int up(int y, int x, int status){
    if(status==1){
        if(y==2) return 0;
        if(arr[y-2][x]=='1') return 0;
        return 1;
    }
    else{
        if(y==1) return 0;
        if(arr[y-1][x-1]=='1' || arr[y-1][x]=='1' || arr[y-1][x+1]=='1') return 0;
        return 1;
    }
}
int down(int y, int x, int status){
    if(status==1){
        if(y==n-1) return 0;
        if(arr[y+2][x]=='1') return 0;
        return 1;
    }
    else{
        if(y==n) return 0;
        if(arr[y+1][x-1]=='1' || arr[y+1][x]=='1' || arr[y+1][x+1]=='1') return 0;
        return 1;
    }
}
int left(int y, int x, int status){
    if(status==0){
        if(x==2) return 0;
        if(arr[y][x-2]=='1') return 0;
        return 1;
    }
    else{
        if(x==1) return 0;
        if(arr[y-1][x-1]=='1' || arr[y][x-1]=='1' || arr[y+1][x-1]=='1') return 0;
        return 1;
    }
}
int right(int y, int x, int status){
    if(status==0){
        if(x==n-1) return 0;
        if(arr[y][x+2]=='1') return 0;
        return 1;
    }
    else{
        if(x==n) return 0;
        if(arr[y-1][x+1]=='1' || arr[y][x+1]=='1' || arr[y+1][x+1]=='1') return 0;
        return 1;
    }
}
int lotate(int y, int x, int status){
    if(status==0){
        if(y==1 || y==n) return 0;
        if(arr[y-1][x-1]=='1' || arr[y-1][x]=='1' || arr[y-1][x+1]=='1') return 0;
        if(arr[y+1][x-1]=='1' || arr[y+1][x]=='1' || arr[y+1][x+1]=='1') return 0;
        return 1;
    }
    else{
        if(x==1 || x==n) return 0;
        if(arr[y-1][x-1]=='1' || arr[y][x-1]=='1' || arr[y+1][x-1]=='1') return 0;
        if(arr[y-1][x+1]=='1' || arr[y][x+1]=='1' || arr[y+1][x+1]=='1') return 0;
        return 1;
    }
}

void bfs(tree t){
    queue<tree> q;
    q.push(t);
    while(!q.empty()){
        int y = q.front().y;
        int x = q.front().x;
        int status = q.front().status;
        int count = q.front().count;
        q.pop();
        // cout<<y<<" "<<x<<" ";
        // if(status==0)cout<<"누워있음시작"<<endl;
        // else cout<<"서있음시작"<<endl;
        if(y==endY && x==endX && status==endStatus){
            cout<<count<<endl;
            return;
        }
        
        if(up(y,x,status)==1){
            if(visited[y-1][x][status]==0){
                tree temp;
                temp.y=y-1; temp.x=x; temp.status=status; temp.count=count+1;
                visited[y-1][x][status]=1;
                q.push(temp);
                // cout<<"up"<<endl;
            }
        }

        
        if(down(y,x,status)==1){
            if(visited[y+1][x][status]==0){
                tree temp;
                temp.y=y+1; temp.x=x; temp.status=status; temp.count=count+1;
                visited[y+1][x][status]=1;
                q.push(temp);
                // cout<<"down"<<endl;
            }
        }
        
        if(left(y,x,status)==1){
            if(visited[y][x-1][status]==0){ 
                tree temp;
                temp.y=y; temp.x=x-1; temp.status=status; temp.count=count+1;
                visited[y][x-1][status]=1;
                q.push(temp);
                // cout<<"<<"<<endl;
            }
        }
        
        if(right(y,x,status)==1){
            if(visited[y][x+1][status]==0){
                tree temp;
                temp.y=y; temp.x=x+1; temp.status=status; temp.count=count+1;
                visited[y][x+1][status]=1;
                q.push(temp);
                // cout<<">>"<<endl;
            }
        }
        
        if(lotate(y,x,status)==1){
            if(visited[y][x][!(status&1)]==0){
                tree temp;
                temp.y=y; temp.x=x; temp.count=count+1;
                if(status==1) temp.status=0;
                else temp.status=1;
                visited[y][x][status]=1;
                q.push(temp);
                // cout<<"lotate"<<endl;
            }
        }
    }
    //실패
    cout<<"0"<<endl;
}

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
            if(arr[i][j]=='B'){
                if(firstY==0 && firstX==0){
                    firstY=i; firstX=j;
                }
                else if (firstY==i) firstStatus=0;  //누워있는 것
                else if(firstX==j) firstStatus=1;   //세워져있는 것
            }
            else if(arr[i][j]=='E'){
                if(endY==0 && endX==0){
                    endY=i; endX=j;
                }
                else if(endY==i) endStatus=0;
                else if(endX==j) endStatus=1;
            }
        }
    }
    // cout<<firstStatus<<" "<<endStatus<<endl;
    if(firstStatus==0) firstX+=1;
    else firstY+=1;
    if(endStatus==0) endX+=1;
    else endY+=1;
    
    tree temp;
    temp.y=firstY; temp.x=firstX; temp.status=firstStatus; temp.count=0;
    visited[firstY][firstX][firstStatus]=1;
    bfs(temp);
    return 0;
}