#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
long long arr[1000001];
long long arr2[1000001][23];
long long one[23];
long long zero[23];

int main(){
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>arr[i];

    for(int i=1; i<=n; i++){
        int temp = arr[i];
        long long result = 0;
        for(int j=1; temp>0; j++){
            int a = temp%2;
            arr2[i][j]=a;
            temp /= 2;
        }
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=21; j++){
            if(arr2[i][j]==1) one[j]++;
            else zero[j]++;
        }
    }

    long long sum=0;
    for(int i=1, j=1; i<=21; i++, j*=2){
        long long temp = one[i]*zero[i];
        sum += (temp*j);
    }
    cout<<sum<<endl;
    int x=10;
    for(int i=1; i<21; x>>=1, i++)
        cout<<x<<" "<<(x&1)<<endl;
    return 0;
}