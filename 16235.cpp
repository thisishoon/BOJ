#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <deque>

using namespace std;
int n, m, k;
int arr[11][11];
int S2D2[11][11];
int dy[8]={-1,-1,-1,0,0,1,1,1};
int dx[8]={-1,0,1,1,-1,-1,0,1};

struct tree{
    int y;
    int x;
    int age;
};
// vector<tree> v;
deque<int> v[11][11];



int comp(tree a, tree b){
    return a.age<b.age;
}

void func(int year){
    //봄
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            // sort(v[i][j].begin(), v[i][j].end());
            for(int a=0; a<v[i][j].size(); a++){
                if(arr[i][j]>=v[i][j][a]){
                    arr[i][j] -= v[i][j][a];
                    v[i][j][a]++;
                }
                else{
                    //실패
                    int tempPoint = a;
                    for(int b=a; b<v[i][j].size(); b++){
                        arr[i][j] += (v[i][j][b]/2);
                    }
                    v[i][j].erase(v[i][j].begin()+a, v[i][j].end());
                    break;
                }
            }
        }
    }
    //가을
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int a=0; a<v[i][j].size(); a++){
                if(v[i][j][a]%5==0){
                    for(int d=0; d<8; d++){
                        int ny = i + dy[d];
                        int nx = j + dx[d];
                        if(nx==0 || ny==0 || nx>n || ny>n) continue;
                        // v[ny][nx].push_back(1);
                        v[ny][nx].push_front(1);
                    }
                }
            }
        }
    }
    //겨울
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            arr[i][j] += S2D2[i][j];
        }
    }
}


int main(){
    // ios_base :: sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    cin>>n>>m>>k;

    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) arr[i][j]=5;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin>>S2D2[i][j];
    for(int i=1; i<=m; i++){
        int a, b, c;    cin>>a>>b>>c;
        v[a][b].push_back(c);
    }
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) sort(v[i][j].begin(), v[i][j].end());
    for(int i=1; i<=k; i++){
        func(i);
    }
    
    int answer = 0;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) answer += v[i][j].size();
    cout<<answer<<endl;
    return 0;
}