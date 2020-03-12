#include <iostream>
#include <algorithm>

using namespace std;
char arr[111][111];
int n;
int result;
int dy[8]={1,1,1,0,0,-1,-1,-1};
int dx[8]={1,0,-1,1,-1,1,0,-1};
void remove(int y, int x);

void check(int y, int x){
    for(int d=0; d<8; d++){
        int nextY = y + dy[d];
        int nextX = x + dx[d];
        if(arr[nextY][nextX]=='0'){
            result-=1;
            arr[y][x]='#';
            return;
        }
    }
    arr[y][x]='*';
    remove(y,x);
}

void remove(int y, int x){
    for(int d=0; d<8; d++){
        int nextY = y + dy[d];
        int nextX = x + dx[d];
        if(nextY==1 || nextY==n || nextX==1 || nextX==n){
            if(arr[nextY][nextX]>'0')
                arr[nextY][nextX] -= 1;
        }
    }
}

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
        }
    }
    
    

    result = (n-2)*(n-2);
    if(n>3){
        for(int i=2; i<=n-2; i++){
            check(2,i); check(i, n-1);
            check(n-1, n-i+1);    check(n-i+1, 2);
        }
    }
    else if(n==3){
        check(1,1);
    }
    else result=0;

    cout<<result<<endl;

    return 0;
}