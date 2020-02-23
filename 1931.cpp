#include <iostream>
#include <algorithm>
using namespace std;
pair<int, int> arr[100001];

int comp(pair<int,int> a, pair<int,int> b){
    if(a.second==b.second) return a.first<b.first;
    else return a.second<b.second;
}

int main(){
    int n;
    cin>>n;
    int result=0;
    for(int i=1; i<=n; i++){
        cin>>arr[i].first>>arr[i].second;
    }
    sort(arr+1, arr+1+n, comp);

    // for(int i=1; i<=n; i++) cout<<arr[i].first<<"@"<<arr[i].second<<endl;
    
    int lastEnd=-1;
    for(int i=1; i<=n; i++){
        if(lastEnd<=arr[i].first){
            result++;
            lastEnd=arr[i].second;
        }
    }
    cout<<result<<endl;
    return 0;
}