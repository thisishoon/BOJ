#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

char arr[6][6];
vector<pair<int, int> > v;
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int main(){
    int n; cin>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            if(arr[i][j]=='T') v.push_back(make_pair(i,j));
        }
            
    for(int i=0; i<n*n; i++){
        for(int j=i+1; j<n*n; j++){
            for(int k=j+1; k<n*n; k++){
                int flag=0; //성공 여부를 판단하기위한 변수
                if(arr[i/n][i%n]=='X'&&arr[j/n][j%n]=='X'&&arr[k/n][k%n]=='X'){
                    arr[i/n][i%n]=0;
                    arr[j/n][j%n]=0;
                    arr[k/n][k%n]=0;

                    for(int t=0; t<v.size(); t++){  //각각 선생님들
                        int y = v[t].first;
                        int x = v[t].second;
                        for(int d=0; d<4; d++){ //4 방향
                            int nextY = y+dy[d];
                            int nextX = x+dx[d];
                            while(0<=nextY && nextY<n && 0<=nextX && nextX<n){
                                int temp = arr[nextY][nextX];
                                if(temp==0 || temp=='T') break; //벽을 만나거나 선생님을 만날 경우
                                else if(temp=='S'){ //학생을 만날 경우
                                    flag=1; 
                                    break;
                                }
                                else if(temp=='X'){//계속 전진
                                    nextY+=dy[d];
                                    nextX+=dx[d];
                                }
                            }
                        }
                    }
                    arr[i/n][i%n]='X';  //다시 벽으로 되돌리기
                    arr[j/n][j%n]='X';
                    arr[k/n][k%n]='X';
                    if(flag==0){  
                        cout<<"YES"<<endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}