#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;
int r, c, t;
pair<int, int> robot[2];
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};
int arr[55][55];
vector<pair<pair<int, int >, int > > v;
int answer;

void spread(){
    int temp[55][55];
    memset(temp, 0, sizeof(temp));
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            if(arr[i][j]>0){
                int cnt=0;
                for(int d=0; d<4; d++){
                    int ny = i + dy[d];
                    int nx = j + dx[d];
                    if(ny==0 || nx==0 || ny>r || nx>c) continue;
                    if(arr[ny][nx]==-1) continue;
                    temp[ny][nx] += arr[i][j]/5;
                    cnt++;
                }

                temp[i][j] += (arr[i][j] - ((arr[i][j]/5) * cnt));
            }
        }
    }
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            arr[i][j] = temp[i][j];
        }
    }
    arr[robot[0].first][robot[0].second]=-1;
    arr[robot[1].first][robot[1].second]=-1;
}
void wind(){
    int firstY = robot[0].first;
    int firstX = robot[0].second;
    int secondY = robot[1].first;
    int secondX = robot[1].second;
    
    for(int i=firstY-1; i>1; i--){
        arr[i][1]=arr[i-1][1];
    }
    for(int i=secondY+1; i<r; i++){
        arr[i][1]=arr[i+1][1];
    }
    for(int j=1; j<c; j++){
        arr[1][j]=arr[1][j+1];
        arr[r][j]=arr[r][j+1];
    }
    for(int i=1; i<firstY; i++){
        arr[i][c]=arr[i+1][c];
    }
    for(int i=r; i>secondY; i--){
        arr[i][c]=arr[i-1][c];
    }
    for(int j=c; j>2; j--){
        arr[firstY][j]=arr[firstY][j-1];
        arr[secondY][j]=arr[secondY][j-1];
    }
    arr[firstY][2]=arr[secondY][2]=0;

    

}

void check(){
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            if(arr[i][j]>0){
                answer += arr[i][j];
            }
        }
    }
}

void spread_print(){
    cout<<"-------------"<<endl;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"--------------"<<endl;
}

int main(){
    scanf("%d %d %d", &r, &c, &t);
    int flag=1;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            scanf("%d", &arr[i][j]);
            if(arr[i][j]==-1 && flag==1){
                robot[0]=make_pair(i,j);
                robot[1]=make_pair(i+1,j);
                flag=0;
            }
        }
    }
    while(t--){
        spread();
        wind();
    }
    check();
    cout<<answer<<endl;

    return 0;
}