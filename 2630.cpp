#include <iostream>
#include <algorithm>
using namespace std;
int arr[130][130];
int result[2];

int func(int y, int x, int n){
    int temp = arr[y][x];
    int half = n/2;
    if(n==1){
        result[temp]++;
        return 0;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(temp!=arr[y+i][x+j]){
                func(y, x, half);
                func(y+half, x, half);
                func(y, x+half, half);
                func(y+half, x+half, half);
                return 0;
            }
        }
    }
    if(temp==0) result[0]++;
    else result[1]++;

    return 0;
}

int main (){
    int n; cin>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) scanf("%d", &arr[i][j]);
    
    func(1, 1, n);
    cout<<result[0]<<endl;
    cout<<result[1]<<endl;
    return 0;
}