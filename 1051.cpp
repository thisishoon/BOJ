#include <iostream>
#include <algorithm>
using namespace std;
char arr[51][51];
int main(){
    int n, m; cin>>n>>m;
    int maximum = min(n,m);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>arr[i][j];
        }
    }
    int result=1;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            for(int a=1; a<=maximum; a++){
                if(i+a > n) break;
                if(j+a > m) break;
                char temp = arr[i][j];
                //cout<<temp<<" "<<arr[i+a][j]<<" "<<arr[i][j+a]<<" "<<arr[i+a][j+a]<<endl;
                if(temp==arr[i+a][j]){
                    if(temp==arr[i][j+a]){
                        if(temp==arr[i+a][j+a]){
                            result = max(result, (a+1)*(a+1));
                        }
                    }
                }
            }
        }
    }
    cout<<result<<endl;

    return 0;
}