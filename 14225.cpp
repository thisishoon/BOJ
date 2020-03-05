#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int arr[22];
int result;
vector<int> v;

void dfs(int index, int sum){
    if(index>n){
        v.push_back(sum);
        return;
    }
    dfs(index+1, sum+arr[index]);
    dfs(index+1, sum);
}

int main(){
    cin>>n;
    for(int i=1; i<=n; i++) cin>>arr[i];
    dfs(1,0);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int result=1;
    for(int i=1; i<v.size(); i++){
        if(v[i]!=result){
            cout<<result<<endl;
            return 0;
        }
        else{
            result++;
        }
    }
    cout<<result<<endl;

    return 0;
}