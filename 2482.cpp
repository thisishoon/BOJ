#include <iostream>
#include <algorithm>

using namespace std;
int n, k;
int answer;
int arr[1001];
const int mod = 1000000003;

void combination(int num, int last){
    if(num==k){
        if(arr[0]==1 && arr[k-1]==n)  return;

        answer= (answer+1)%mod;
        return;
    }
    for(int i=last; i<=n; i++){
        arr[num]=i;
        combination(num+1, i+2);
        arr[num]=0;
    }
}

int main(){
    cin>>n>>k;
    combination(0, 1);
    cout<<answer<<endl;

    return 0;
}