#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
int n = 4;
struct fish{
    int y;
    int x;
    int d;
};
vector<fish> fishes;

int dead[20];
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int sum;
int map[4][4];

void simulation(int sy, int sx, int sd, int cnt, int arr[4][4], int death[20], vector<fish> f){
    //물고기 이동
    for(int i=1; i<=16; i++){
        if(death[i]) continue;
        int cy = f[i].y;
        int cx = f[i].x;
        int cd = f[i].d;
        for(int k=0; k<8; k++){
            int nd = (cd+k)%8;
            int ny = cy + dy[nd];
            int nx = cx + dx[nd];
            // cout<<i<<","<<k<<endl;

            if(ny<0 || nx<0 || ny>3 || nx>3) continue;

            int next = arr[ny][nx];
            if(next==-1) continue;

            if(next==0){    //비어 있음
                f[i] = {ny, nx, nd};
                arr[cy][cx] = 0;
                arr[ny][nx] = i;
                break;
            }   
            else{   //물고기가 있음
                f[i].d = nd;
                swap(f[i].y, f[next].y);
                swap(f[i].x, f[next].x);
                swap(arr[cy][cx], arr[ny][nx]);
                break;
            }
        }
    }

    int flag=1;
    for(int dist=0; dist<3; dist++){    //상어는 최대 3번 이동 가능
        int nsy = sy + dy[sd], nsx = sx + dx[sd];
        sy = nsy, sx = nsx;
        if(nsy<0 || nsx<0 || nsy==4 ||nsx==4) break;
        int arr2[4][4];
        int death2[20];
        memcpy(arr2, arr, sizeof(arr2));
        memcpy(death2, death, sizeof(death2));
        vector<fish> f2 = f;

        if(arr2[nsy][nsx]>0){ //먹을 게 있으면
            int num = arr2[nsy][nsx];
            death2[num] = 1;
            arr2[nsy-dy[sd]][nsx-dx[sd]] = 0;
            arr2[nsy][nsx] = -1;
            simulation(nsy, nsx, f[num].d, cnt+num, arr2, death2, f2);
            flag=0;
        }
        // sy = nsy;
        // sx = nsx;
    }

    // int nsy = sy + dy[sd], nsx = sx + dx[sd];
    // while(nsy>=0 && nsx>=0 && nsy<=3 && nsx<=3){
    //     int arr2[4][4];
    //     int death2[20];
    //     vector<fish> f2 = f;
    //     memcpy(arr2, arr, sizeof(arr2));
    //     memcpy(death2, death, sizeof(death2));

    //     if(arr2[nsy][nsx]>0){
    //         int num = arr2[nsy][nsx];
    //         death2[num] = 1;
    //         arr2[sy][sx] = 0;
    //         arr2[nsy][nsx] = -1;
    //         simulation(nsy, nsx, f[num].d, cnt+num, arr2, death2, f2);
    //         flag=0;
    //     }
    //     nsy = nsy + dy[sd];
    //     nsx = nsx + dx[sd];
    // }

    if(flag){
        sum = max(sum, cnt);
        return;
    }
    return;
}

int main(){
    fishes.resize(17);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int a, b; cin>>a>>b;
            map[i][j]=a;
            fishes[a] = {i, j, b-1};
        }
    }

    int first_fish = map[0][0];
    int first_dir = fishes[first_fish].d;
    dead[first_fish] = 1;
    map[0][0] = -1;
    simulation(0, 0, first_dir, first_fish, map, dead, fishes);

    cout<<sum<<endl;
    return 0;
}