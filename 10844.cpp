#include <iostream>
#include <algorithm>
using namespace std;
int arr[101][10];

int main(){
    int n;
    cin>>n;
    for(int i=1; i<=9; i++)
        arr[1][i]=1;

    for(int i=2; i<=n; i++){
        for(int j=0; j<=9; j++){
            if(j==0){
                arr[i][j] = arr[i-1][1];
            }
            else if(j==9){
                arr[i][j] = arr[i-1][8];
            }
            else{
                arr[i][j] = (arr[i-1][j-1] + arr[i-1][j+1])%1000000000;
            }
        }
    }
    int result=0;
    for(int i=0; i<=9; i++)
        result = (result + arr[n][i])%1000000000;

    cout<<result<<endl;

    return 0;
}