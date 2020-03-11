#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int arr[4][10];
int k;
int dir[4];

void rotate(int arr[], int d){
    if(d==-1){   //시계방향
        int temp[10];
        for(int i=0; i<8; i++) temp[i]=arr[i];
        for(int i=0; i<8; i++){
            arr[i] = temp[(i+1)%8];
        }
    }
    else if(d==1){   //반시계방향
        int temp[10];
        for(int i=0; i<8; i++) temp[i]=arr[i];
        for(int i=0; i<8; i++){
            arr[i] = temp[(i+7)%8];
        }
    }
    return;
}

void solve(int idx, int d){
    for(int i=idx; i<3; i++){
        if(arr[i][2]!=arr[i+1][6]){
             dir[i+1] = -dir[i];
        }
    }
    for(int i=idx; i>0; i--){
        if(arr[i][6]!=arr[i-1][2]) dir[i-1] = -dir[i];
    }
    
    for(int i=0; i<4; i++){
        rotate(arr[i], dir[i]);
    }
}

int main(){
    for(int i=0; i<4; i++){
        for(int j=0; j<8; j++){
            scanf("%1d", &arr[i][j]);
        }
    }

    scanf("%d", &k);
    while(k--){
        int index; 
        int direction; 
        scanf("%d %d", &index, &direction);
        memset(dir, 0, sizeof(dir));
        dir[index-1] = direction;
        solve(index-1, dir[index-1]);
    }
    
    int result = 0;
    int binary = 1;
    for(int i=0; i<4; i++){
        if(arr[i][0]==1) result += (binary<<i);
    }
    printf("%d\n", result);
    return 0;
}