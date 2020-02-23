#include <iostream>
#include <algorithm>
using namespace std;

double arr[1000001];
int main(){
    int n;
    cin>>n;
    arr[6]=1;
    
    for(int i=7; i<=n+6; i++){
        arr[i] = (arr[i-1]+arr[i-2]+arr[i-3]+arr[i-4]+arr[i-5]+arr[i-6])/6 + 1;
    }
    printf("%.10f\n", arr[n+5]);
    


    return 0;
}