#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[3]={3, 2, 1};
int visited[4];
int permutation_arr[3];

void prin(int temp[]){
    for(int i=0; i<3; i++){
        cout<<temp[i]<<" ";
    }
    cout<<endl;
}

void permutation(){
    sort(arr, arr+3);   //net_permutation 함수를 사용하려면 정렬이 되어있어야한다
    prin(arr);
    while(next_permutation(arr, arr+3)){
        prin(arr);
    }
}

void permutation_dfs(int cnt){
    if(cnt==3){
        prin(permutation_arr);
        return;
    }
    for(int i=1; i<=3; i++){
        if(visited[i]==1) continue;
        visited[i]=1;
        permutation_arr[cnt]=i;
        permutation_dfs(cnt+1);
        permutation_arr[cnt]=0;
        visited[i]=0;
    }
    return;
}


int main(){
    permutation();
    cout<<"@@@@"<<endl;
    permutation_dfs(0);
    return 0;
}