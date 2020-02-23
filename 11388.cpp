#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>arr[i];
    
    sort(arr+1, arr+1+n);
    int result=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            result+= arr[j];
        }
    }
    cout<<result<<endl;
    return 0;
}