#include <iostream>
#include <algorithm>

using namespace std;
int arr_zero[41];
int arr_one[41];

int main(){
    int t;
    cin>>t;
    arr_zero[0]=1;
    arr_one[0]=0;
    arr_zero[1]=0;
    arr_one[1]=1;
    while(t--){
        int n;
        cin>>n;
        for(int i=2; i<=n; i++){
            arr_zero[i]=arr_zero[i-1]+arr_zero[i-2];
            arr_one[i]=arr_one[i-1]+arr_one[i-2];
        }
        cout<<arr_zero[n]<<" "<<arr_one[n]<<endl;
    }


    return 0;
}