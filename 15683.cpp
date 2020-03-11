#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int n, m;
char arr[10][10];
// char temp[10][10];
int result=999999999;
int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};
vector<pair<pair<int, int>, char> > v;

void check(){
    int empty=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(arr[i][j]=='0') empty++;
        }
    }
    result = min(result, empty);
}

void mapCopy(char arr1[][10], char (*arr2)[10]){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            arr2[i][j] = arr1[i][j];
        }
    }
}

void see(int y, int x, int dir){
    while(1){
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];
        if(nextY==0 || nextX==0 || nextY>n || nextX>m) return;
        if(arr[nextY][nextX]=='6') return;
        if(arr[nextY][nextX]=='0'){
            arr[nextY][nextX]='#';
        }
        y = nextY; x = nextX;
    }
}

void dfs(int cnt){
    if(cnt==v.size()){
        check();
        return;
    }
    int y = v[cnt].first.first;
    int x = v[cnt].first.second;
    char kind = v[cnt].second;
    if(kind=='1'){
        for(int d=0; d<4; d++){
            char temp[10][10];
            mapCopy(arr, temp);
            see(y, x, d);
            dfs(cnt+1);
            mapCopy(temp, arr);
        }
    }
    else if(kind=='2'){
        for(int d=0; d<2; d++){
            char temp[10][10];
            mapCopy(arr, temp);
            see(y, x, d);
            see(y, x, d+2);
            dfs(cnt+1);
            mapCopy(temp, arr);
        }
    }
    else if(kind=='3'){
        for(int d=0; d<4; d++){
            char temp[10][10];
            mapCopy(arr, temp);
            see(y, x, d);
            see(y, x, (d+1)%4);
            dfs(cnt+1);
            mapCopy(temp, arr);
        }
    }
    else if(kind=='4'){
        for(int d=0; d<4; d++){
            char temp[10][10];
            mapCopy(arr, temp);
            see(y, x, d);
            see(y, x, (d+1)%4);
            see(y, x, (d+2)%4);
            dfs(cnt+1);
            mapCopy(temp, arr);
        }
    }
    else{
        char temp[10][10];
        mapCopy(arr, temp);
        see(y, x, 0);
        see(y, x, 1);
        see(y, x, 2);
        see(y, x, 3);
        dfs(cnt+1);
        mapCopy(temp, arr);
    }
    return;
}

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>arr[i][j];
            if(arr[i][j]>'0' && arr[i][j]<'6'){
                v.push_back(make_pair(make_pair(i,j), arr[i][j]));
            }
        }
    }
    
    dfs(0);
    cout<<result<<endl;


    return 0;
}