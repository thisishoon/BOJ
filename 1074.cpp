#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int N, r, c;
int arr[50][50];
int cnt;
int dy[4]={0,0,1,1};
int dx[4]={0,1,0,1};

void divide(int n, int y, int x){
    if(n==2){
        for(int d=0; d<4; d++){
            int ny = y+dy[d];
            int nx = x+dx[d];
            if(ny==r && nx==c){
                cout<<cnt<<endl;
                return;
            }
            // cout<<ny<<" "<<nx<<" "<<r<<" "<<c<<endl;
            cnt++;
        }
        return;
    }
    divide(n/2, y, x);
    divide(n/2, y, x + n/2);
    divide(n/2, y + n/2, x);
    divide(n/2, y + n/2, x + n/2);

    return;
}

int main(){
    cin>>N>>r>>c;
    divide(pow(2, N), 0, 0);

    return 0;
}