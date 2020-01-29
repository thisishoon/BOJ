#include <iostream>
#include <algorithm>

using namespace std;
int arr[100001];
int num[100001];
int main(){
    int n, m;
    cin>>n;
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+n);
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        scanf("%d", &num[i]);
        int left=0;
        int right=n-1;
        int mid;
        int flag=0;
        int target = num[i];
        while(left<=right){
            mid = (left+right)/2;
            //cout<<i<<" "<<left<<" "<<right<<" "<<mid<<endl;
            if(arr[mid]==target){
                flag=1;
                break;
            }
            else if(arr[mid]<target){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        if(flag==0){
            //cout<<"0"<<endl;
            printf("0\n");
        }
        else{
            //cout<<"1"<<endl;
            printf("1\n");
        }
    }
    


    return 0;
}