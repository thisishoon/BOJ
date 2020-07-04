#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
pair<int, int> arr[200002];
int answer;
priority_queue<int, vector<int>, greater<int> > pq;

int main(){
    int n; cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i].first>>arr[i].second;
    }
    sort(arr, arr+n);

    for(int i=0; i<n; i++){
        pq.push(arr[i].second);
        
        while(pq.size() > arr[i].first){
            pq.pop();                
        }
    }
    
    while(!pq.empty()){
        answer += pq.top();
        pq.pop();
    }

    cout<<answer<<endl;
    return 0;
}