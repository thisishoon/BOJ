#include <iostream>
#include <algorithm>

using namespace std;
int coin[11];
int main(){
    int n, k, result=0;
    cin>>n>>k;
    for(int i=1; i<=n; i++) 
        cin>>coin[i];
    for(int i=n; i>=1; i--){
        if(k==0) break;
        if(k<coin[i]) continue;
        while(k>=coin[i]){
            result++;
            k-=coin[i];
        }
    }
    
    cout<<result<<endl;
    return 0;
}