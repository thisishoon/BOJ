#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#include <cstring>


using namespace std;
int r, c, m;
struct shark{
    int s;
    int d;
    int z;
};

shark arr[111][111];

int dy[5]={100, -1,1,0,0};
int dx[5]={100, 0,0,1,-1};

int answer=0;

void kill(int x){
    for(int i=1; i<=r; i++){
        if(arr[i][x].z){
            answer += arr[i][x].z;
            shark sh; sh.d=0; sh.s=0; sh.z=0;
            arr[i][x] = sh;
            break;
        }
    }
}

void run(){
    shark temp[111][111];
    // for(int i=1; i<=r; i++){
    //     for(int j=1; j<=c; j++){
    //         shark sh; sh.d=0; sh.s=0; sh.z=0;
    //         temp[i][j]=sh;
    //     }
    // }
    memset(temp, 0, sizeof(temp));
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            if(arr[i][j].z){
                int s = arr[i][j].s;
                int d = arr[i][j].d;
                int z = arr[i][j].z;
                int y= i; int x=j;
                
                int cnt;
                if(d<=2) cnt = s % ((r-1)*2);
                else cnt = s % ((c-1)*2);

                for(int z=0; z<cnt; z++){
                    if(d==1 && y==1) d=2;
                    else if(d==2 && y==r) d=1;
                    else if(d==3 && x==c) d=4;
                    else if(d==4 && x==1) d=3;
                    y += dy[d]; x += dx[d];
                }
                //완료

                if(temp[y][x].z){  //누군가 있다면
                    if(temp[y][x].z < arr[i][j].z){
                        temp[y][x].d=d; temp[y][x].z=z; temp[y][x].s=s;
                    }
                }
                else{
                    temp[y][x].d=d; temp[y][x].z=z; temp[y][x].s=s;
                }
            }
        }
    }
    memcpy(arr, temp, sizeof(temp));
}

int main(){
    cin>>r>>c>>m;
    for(int i=1; i<=m; i++){
        int a, b, s, d, z;
        cin>>a>>b>>s>>d>>z;
        shark sh; sh.s=s; sh.d=d; sh.z=z;
        arr[a][b]=sh;
    }
    for(int j=1; j<=c; j++){
        kill(j);
        run();
    }
    cout<<answer<<endl;

    return 0;
}