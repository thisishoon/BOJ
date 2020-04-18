#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
int arr[111][111];
int n;
int dy[4]={0,-1,0,1};
int dx[4]={1,0,-1,0};
int direction;
int result;

vector<int> dragon[11];

void before_curve(){
    dragon[0].push_back(0);
    for(int i=1; i<=10; i++){
        dragon[i].resize(dragon[i-1].size()*2);
        auto it = copy(dragon[i-1].begin(), dragon[i-1].end(), dragon[i].begin());
        copy(dragon[i-1].rbegin(), dragon[i-1].rend(), it);
        for(int j=dragon[i].size()/2; j<dragon[i].size(); j++){
            dragon[i][j]++;
        }
    }
}

void curve(int y, int x, int d, int g){
    arr[y][x]++;
    int curY = y; int curX = x;

    for(int i=0; i<pow(2,g); i++){
        int direction = dragon[g][i];
        int nextY = curY + dy[(direction+d)%4];
        int nextX = curX + dx[(direction+d)%4];
    
        if(nextY<0 || nextX<0 || nextY>100 || nextX>100) continue;
        arr[nextY][nextX]++;
        curY=nextY; curX=nextX;
    }
}

void check(){
    for(int i=0; i<=100; i++){
        for(int j=0; j<=100; j++){
            if(arr[i][j]>0 && arr[i+1][j]>0 && arr[i][j+1]>0 && arr[i+1][j+1]>0){
                result++;
            }
        }
    }
}


int main(){
    cin>>n;
    before_curve();
    
    for(int i=1; i<=n; i++){
        int x, y, d, g;
        cin>>x>>y>>d>>g;
        curve(y,x,d,g);
    }

    check();
    cout<<result<<endl;
    
    return 0;
}