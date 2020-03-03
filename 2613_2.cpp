#include <iostream>
#include <algorithm>
using namespace std;
int arr[303];
int n,m; 

int func(int mid){
    int sum=0;
    int count=1;
    for(int i=1; i<=n; i++){
        sum+=arr[i];
        if(sum>mid){
            count++;
            sum=arr[i];
        }
    }
    if(count<=m) return 1;
    else return 0;
}

int main(){
    cin>>n>>m;
    int left=0, right=0;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
        left=max(left, arr[i]);
        right+=arr[i];
    }
    int mid=0;
    int result=0;
    while(left<=right){
        mid = (left+right)/2;
        if(func(mid)){ right = mid-1; result = mid;}
        else left = mid+1;
    }
    cout<<result<<endl;
    int sum=0; int count=0;
    for(int i=1; i<=n; i++){
        sum+=arr[i];
        count++;
        if(sum>result){
            sum=arr[i];
            cout<<count-1<<" ";
            count=1;
            m--;
        }
        if(n-i+1==m){
            while(m--){
                cout<<count<<" ";
                count=1;
            }
        }
    }
    return 0;
}