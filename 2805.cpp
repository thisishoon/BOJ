#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[1000111];
int main(){
    int n, m;
    cin>>n>>m;
    
    int mx=0;
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
        if(mx<arr[i]) mx=arr[i];
    }
    int left=0;
    int right=mx;
    int mid;
    int result=0;   //초기화를 안했다
    while(left<=right){
        mid=(left+right)/2;
        long long income=0;
        for(int i=0; i<n; i++){ //범위를 잘못잡았다.
            int temp=arr[i]-mid;
            if(temp<0) temp=0;
            income+=temp;
        }
        if(income>=m){
            left=mid+1;
            if(result<mid) result=mid;
        }
        else {
            right=mid-1;
        }
    }
    printf("%d", result);

    return 0;
}