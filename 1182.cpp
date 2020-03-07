#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, s;
int arr[22];
int result;

void dfs(int index, int sum, int length){
    
    if(index==n){
        if(length>0){
            //cout<<index<<" "<<sum<<endl;
            if(sum==s) result++;
        }
        return;
    }
    
    dfs(index+1, sum+arr[index+1], length+1);
    dfs(index+1, sum, length);
}


int main(){
    cin>>n>>s;
    for(int i=1; i<=n; i++) cin>>arr[i];
    dfs(0, 0, 0);
    cout<<result<<endl;
    return 0;
}
