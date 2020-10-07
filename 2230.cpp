#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
int arr[100001];


int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>arr[i];
    sort(arr, arr+n);
    int left=0;
    int right=0;
    int answer=2100000000;
    while(left<=right && right<n){
        int diff = arr[right] - arr[left];
        if(diff>=m){
            answer = min(answer, diff);
            left++;
        }
        else{
            right++;
        }
    }
    cout<<answer<<endl;
    return 0;
}