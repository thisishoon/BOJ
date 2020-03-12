#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;
int n, m, h;
int arr[40][40];

int simulation(){
    for(int i=1; i<=n; i++){
        int y = 0; int x = i;
        while(y<h+1){
            y = y + 1;
            int nextX = x;
            if(arr[y][nextX]==2){ //좌
            x-=1;
            }
            else if(arr[y][nextX]==1){    //우
            x+=1;
            }
        }
        if(x!=i){
            return 0;
        }
    }
    return 1;
}

void backtrack(int cnt, int num, int y, int x){
    if(cnt==num){
        if(simulation()){ //성공  
            cout<<num<<endl;
            exit(0);
        }
        return ;
    }
    for(int i=y; i<=h; i++){
        for(int j=x; j<n; j++){
            if(arr[i][j]==0 && arr[i][j+1]==0){
                arr[i][j]=1;
                arr[i][j+1]=2;
                
                if(j>=n-1){
                    backtrack(cnt+1, num, i+1, 1);
                }
                else backtrack(cnt+1, num, i, 1);
                arr[i][j]=arr[i][j+1]=0;
            }
        }
    }
    return;
}


int main(){
    scanf("%d %d %d", &n, &m, &h);
    for(int i=0; i<m; i++){
        int a, b; scanf("%d %d", &a, &b);
        arr[a][b]=1;
        arr[a][b+1]=2;
    }
    for(int i=0; i<=3; i++){
        backtrack(0, i, 1, 1);
    }
    
    cout<<"-1"<<endl;
    return 0;
}