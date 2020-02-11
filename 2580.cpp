#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[10][10];
vector<pair<int, int> > v;

int check_y(int a, int num){
    for(int i=0; i<9; i++){
        if(arr[a][i]==num) return 0;
    }
    return 1;
}
int check_x(int b, int num){
    for(int i=0; i<9; i++){
        if(arr[i][b]==num) return 0;
    }
    return 1;
}
int check_square(int a, int b, int num){
    int start_y=(a/3)*3;
    int start_x=(b/3)*3;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(arr[start_y + i][start_x + j] == num) return 0;
        }
    }
    return 1;
}

int backtrack(int cnt){
    if(cnt==v.size()){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
        exit(0);
    }
    //백트래킹 시작
    int y = v[cnt].first;
    int x = v[cnt].second;
    
    for(int i=1; i<=9; i++){     //특정 숫자가 가능하다고 가정
        //cout<<y<<","<<x<<"="<<i<<" "<<check_y(y,i)<<" "<<check_x(x,i)<<" "<<check_square(y,x,i)<<endl;

        if(check_y(y, i) && check_x(x, i) && check_square(y,x,i)){
            arr[y][x]=i;
            backtrack(cnt+1);
            arr[y][x]=0;
        }
    }
    return 0;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            int temp;
            scanf("%d", &temp);
            arr[i][j]=temp;
            if(temp==0){
                v.push_back(make_pair(i,j));
            }
        }
    }
    backtrack(0);
    
    return 0;
}