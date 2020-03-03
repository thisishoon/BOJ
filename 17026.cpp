#include <iostream>
#include <algorithm>

using namespace std;
pair<int, int> arr[100005];

int comp(pair<int, int> a, pair<int, int> b){
    if(a.first==b.first) return a.second>b.second;
    return a.first<b.first;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    for(int i=1; i<=n; i++){
        int x, y;
        cin>>x>>y;
        arr[i].first=x-y;
        arr[i].second=x+y;
    }
    sort(arr+1, arr+1+n, comp);
    int result = 0;
    int max_x = -999999999;
    for(int i=1; i<=n; i++){
        if(max_x<arr[i].second){
            max_x = arr[i].second;
            result++;
        }
    }
    cout<<result<<endl;
    return 0;
}
