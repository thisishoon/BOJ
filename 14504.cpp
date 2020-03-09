#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;
int n;
pair<int, int> arr[22];
int result;

int dfs(int index, int cost, int time){
    
    if(index>n){
        result = max(result, cost);
        return result;
    }
    if(index+arr[index].first-1 <= n){

        dfs(index+arr[index].first, cost+arr[index].second, time-arr[index].first);
        dfs(index+1, cost, time-1);
    }
    else{
        dfs(index+1, cost, time-1);
    }
    return 0;
}
int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i].first>>arr[i].second;
    }
    dfs(1, 0, n);
    cout<<result<<endl;
    return 0;
}