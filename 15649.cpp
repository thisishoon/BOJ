#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[9];
int visited[9];

int backtrack(int cnt){
    if(cnt==m){
        for(int i=0; i<m; i++)
            cout<<arr[i]<<" ";
        cout<<"\n";
        return 0;
    }
    
    for(int i=1; i<=n; i++){
        if(arr[cnt-1]<=i){
            //visited[i]=1;
            arr[cnt]=i;
            backtrack(cnt+1);
            //visited[i]=0;
        }
    }
    return 0;
}

int main(){
    
    cin>>n>>m;
    backtrack(0);
    return 0;
}