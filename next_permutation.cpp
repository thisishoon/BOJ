#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[3]={3, 2, 1};

void prin(){
    for(int i=0; i<3; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    sort(arr, arr+3);   //net_permutation 함수를 사용하려면 정렬이 되어있어야한다
    prin();
    while(next_permutation(arr, arr+3)){
        prin();
    }
    
    return 0;
}