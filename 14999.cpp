#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int y, x;
int k;
int arr[22][22];

int dy[5]={0,0,0,-1,1};
int dx[5]={0,1,-1,0,0};
int dice[7];

int changeDice(int d){
    int nextY = y+dy[d];
    int nextX = x+dx[d];
    if(nextY<0 || nextX<0 || nextY>=n || nextX>=m) return 0;
    y = nextY;
    x = nextX;
    int temp[7];
    for(int i=1; i<=6; i++) temp[i]=dice[i];
    if(d==1){//동
        dice[1]=temp[4];
        dice[4]=temp[6];
        dice[6]=temp[3];
        dice[3]=temp[1];
    }
    else if(d==2){//서
        dice[1]=temp[3];
        dice[3]=temp[6];
        dice[6]=temp[4];
        dice[4]=temp[1];
    }
    else if(d==3){//북
        dice[1]=temp[5];
        dice[5]=temp[6];
        dice[6]=temp[2];
        dice[2]=temp[1];
    }
    else if(d==4){//남
        dice[1]=temp[2];
        dice[2]=temp[6];
        dice[6]=temp[5];
        dice[5]=temp[1];
    }
    return 1;
}

int main(){
    cin>>n>>m>>y>>x>>k;
    for(int i=0; i<n; i++)  for(int j=0; j<m; j++) cin>>arr[i][j];
    for(int i=0; i<k; i++){
        int query;
        cin>>query;
        if(changeDice(query)){
            cout<<dice[1]<<endl;
            if(arr[y][x]==0) arr[y][x]=dice[6];
            else{
                dice[6]=arr[y][x];
                arr[y][x]=0;
            }
        }
    }
    

    return 0;
}