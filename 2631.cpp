#include <iostream>
#include <algorithm>

using namespace std;

int dp[202];
int arr[202];

int main(){
    int n; cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    for(int i=1; i<=n; i++){
        dp[i]=1;
    }
    for(int i=2; i<=n; i++){
        for(int j=1; j<i; j++){
            if(arr[j]<arr[i]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    int answer=0;
    for(int i=1; i<=n; i++){
        answer = max(answer, dp[i]);
    }
    cout<<n-answer<<endl;
    
    return 0;
}