#include <iostream>
#include <algorithm>

using namespace std;
int arr[222][222];
const int mod = 1000000000;

int main(){
    int n, k; cin>>n>>k;
    for(int i=0; i<=n; i++){
        arr[1][i]=1;
    }
    for(int i=2; i<=k; i++){
        for(int j=0; j<=n; j++){
            for(int l=0; l<=j; l++){
                arr[i][j] =  (arr[i][j] + arr[i-1][j-l])%mod;
            }
        }
    }

    cout<<arr[k][n]<<endl;



    return 0;
}