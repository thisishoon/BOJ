#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, k, l;
int arr[111][111];
vector<pair<int, char> > v;
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};
int current_d;
int result;
int t=0;
queue<pair<int, int> > q;
void dfs(int y, int x){
    // cout<<y<<" "<<x<<"시작"<<endl;
    

    int nextY = y + dy[current_d];
    int nextX = x + dx[current_d];
    // cout<<nextY<<" "<<nextX<<"다음"<<endl;
    result++;
    if(nextY==0 || nextX==0 || nextY>n || nextX>n || arr[nextY][nextX]==1){
        cout<<result<<endl;
        return;
    }
    q.push(make_pair(nextY, nextX));

    if(arr[nextY][nextX]==2){   //사과가 있다면
        arr[nextY][nextX]=1;
    }
    else if(arr[nextY][nextX]==0){   //없다면 꼬리를 지운다
        arr[nextY][nextX]=1;
        int tailY = q.front().first;
        int tailX = q.front().second;
        q.pop();
        // cout<<tailY<<" "<<tailX<<"꼬리지우기"<<endl;
        arr[tailY][tailX]=0;
    }
    if(v[t].first == result){
        // cout<<nextY<<" "<<nextX<<"에서 방향틀기"<<endl;
        if(v[t].second=='L'){
            current_d = (current_d+4-1)%4;
        }
        else{   //오른쪽
            current_d = (current_d+4+1)%4;
        }
        t++;
    }
    dfs(nextY, nextX);
}

int main(){
    cin>>n>>k;
    for(int i=1; i<=k; i++){
        int a, b;   cin>>a>>b;
        arr[a][b]=2;    //사과
    }
    cin>>l;
    for(int i=1; i<=l; i++){
        int a; char b; cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    arr[1][1]=1;
    q.push(make_pair(1,1));
    dfs(1,1);
    return 0;
}