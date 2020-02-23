#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int arr[1001];
int increaseDP[1001];
int decreaseDP[1001];

int main(){
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
        increaseDP[i]=1;
        decreaseDP[i]=1;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<i; j++){
            if(arr[i]>arr[j]){
                increaseDP[i]=max(increaseDP[i], increaseDP[j]+1);
            }
        }
    }
    for(int i=n; i>=1; i--){
        for(int j=n; j>i; j--){
            if(arr[i]>arr[j]){
                decreaseDP[i]=max(decreaseDP[i], decreaseDP[j]+1);
            }
        }
    }
    int result=0;
    for(int i=1; i<=n; i++){
        result=max(result, increaseDP[i]+decreaseDP[i]-1);
    }
    // for(int i=1; i<=n; i++){
    //     cout<<increaseDP[i]<<" "<<decreaseDP[i]<<endl;
    // }
    cout<<result<<endl;


    return 0;
}