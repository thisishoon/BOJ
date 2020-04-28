#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <string>

using namespace std;
pair<int, int> arr[100001];

int comp(pair<int, int>a, pair<int, int> b){
    return a.first<b.first;
}

int main(){
    int n; cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i].first>>arr[i].second;
    }
    // sort(arr+1, arr+1+n);
    for(int i=1; i<=n; i++){
        int temp=0;
        int start = arr[i].first;
        int end = arr[i].second;
        for(int j=1; j<=n; j++){
            if(i==j) continue;
            if(arr[j].first<start && arr[j].second>start) temp++;
        }
        cout<<temp<<endl;
    }


    return 0;
}