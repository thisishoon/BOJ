#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int n;

int answer=999999999;
int arr[22][22];

void func(int x, int y, int d1, int d2){
    int seperate[22][22];
    memset(seperate, 0, sizeof(seperate));
    int cnt[5];
    memset(cnt, 0, sizeof(cnt));
    
    for(int i=0; i<=d1; i++){
        if(x+i>0 && x+i<=n && y-i>0 && y-i<=n){
            seperate[x+i][y-i]=5;
        }
        if(x+d2+i>0 && x+d2+i<=n && y+d2-i>0 && y+d2-i<=n){
            seperate[x+d2+i][y+d2-i]=5;
        }
    }    
    for(int i=0; i<=d2; i++){
        if(x+i>0 && x+i<=n && y+i>0 && y+i<=n){
            seperate[x+i][y+i]=5;
        }
            
        if(x+d1+i>0 && x+d1+i<=n && y-d1+i>0 && y-d1+i<=n){
            seperate[x+d1+i][y-d1+i]=5;
        }
    }


    for(int i=1; i<=n; i++){
        int start=0;
        int end=0;
        for(int j=1; j<=n; j++){
            if(seperate[i][j]==5 && start==0) start=j;
            else if(seperate[i][j]==5 && start!=0) end=j;
        }
        if(start && end){
            for(int j=start+1; j<end; j++){
                seperate[i][j]=5;
            }
        }
        else if(start);
    }
    
    for(int i=1; i<x+d1; i++){
        for(int j=1; j<=y; j++){
            if(i==0 || j==0 || i>n || j>n) continue;

            if(seperate[i][j]==5) break;
            seperate[i][j]=1;
        }
    }

    for(int i=1; i<=x+d2; i++){
        for(int j=y+1; j<=n; j++){
            if(i==0 || j==0 || i>n || j>n) continue;
            if(seperate[i][j]==5) continue;
            seperate[i][j]=2;
        }
    }

    for(int i=x+d1; i<=n; i++){
        for(int j=1; j<y-d1+d2; j++){
            if(i==0 || j==0 || i>n || j>n) continue;
            if(seperate[i][j]==5) break;
            seperate[i][j]=3;
        }
    }

    for(int i=x+d2+1; i<=n; i++){
        for(int j=y-d1+d2; j<=n; j++){
            if(i==0 || j==0 || i>n || j>n) continue;
            if(seperate[i][j]==5) continue;
            seperate[i][j]=4;
        }
    }

    int mx=-1;
    int mn=999999999;

    int result[6];
    memset(result, 0, sizeof(result));


    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int team = seperate[i][j];
            result[team] += arr[i][j];
        }
    }
    
    for(int i=1; i<=5; i++){
        mx = max(mx, result[i]);
        mn = min(mn, result[i]);
    }
    answer = min(answer, mx-mn);
    

}


int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int d1=1; d1<=n; d1++){
                for(int d2=1; d2<=n; d2++){
                    if(i+d1+d2<=n){
                        if(1<=j-d1 && j+d2<=n){
                             func(i,j,d1,d2);
                        }
                    }
                }
            }
        }
    }
    cout<<answer<<endl;
    return 0;
}