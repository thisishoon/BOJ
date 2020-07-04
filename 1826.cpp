#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int answer;
int n;
int l, p;
priority_queue<int> pq;
vector<pair<int, int> > v;

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        int a, b; cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(), v.end());
    cin>>l>>p;
    int cur=0;

    while(p<l){
        while(v.size()>=1 && v.front().first <= p ){
            pq.push(v.front().second);
            v.erase(v.begin());
        }
        if(pq.empty()){
            answer=-1;
            break;
        }
        answer++;
        p += pq.top();
        pq.pop();
    }
    cout<<answer<<endl;
    return 0;
}