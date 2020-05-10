#include <iostream>
#include <algorithm>
using namespace std;
int n;
int arr[4];
int minarr[4];

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        int a, b, c;
        cin>>a>>b>>c;
        int maxDP[4];
        int minDP[4];
        maxDP[1] = max(arr[1], arr[2]) + a;
        maxDP[2] = max(max(arr[1],arr[2]),arr[3]) + b;
        maxDP[3] = max(arr[2], arr[3]) + c;

        minDP[1] = min(minarr[1], minarr[2]) + a;
        minDP[2] = min(min(minarr[1],minarr[2]),minarr[3]) + b;
        minDP[3] = min(minarr[2], minarr[3]) + c;
        arr[1]=maxDP[1]; arr[2]=maxDP[2]; arr[3]=maxDP[3];
        minarr[1]=minDP[1]; minarr[2]=minDP[2]; minarr[3]=minDP[3];
    }

    
    cout<<max(arr[1], max(arr[2], arr[3]))<<endl;
    cout<<min(minarr[1], min(minarr[2], minarr[3]));
    

    return 0;
}