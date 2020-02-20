#include <iostream>
#include <algorithm>

using namespace std;
pair<int, int> arr[101];
int dp[101];
int main(){
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        int a, b;
        cin>>a>>b;
        arr[i]=make_pair(a,b);
    }
    sort(arr+1, arr+n+1);
    for(int i=1; i<=n; i++){
        dp[i]=1;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<i; j++){
            if(arr[j].second<arr[i].second){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    int result=0;
    for(int i=1; i<=n; i++)
        result = max(result, dp[i]);

    //cout<<result<<endl;
    cout<<n-result<<endl;
    return 0;
}