#include <iostream>
#include <set>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;

int main(){
    int n; cin>>n;
    for(int i=1; i<=n; i++){
        int op; scanf("%d", &op);
        if(op==0){
            if(pq.empty()){
                cout<<"0\n";
                continue;
            }
            cout<<pq.top()<<"\n";
            pq.pop();
        }
        else{
            pq.push(op);
        }
    }


    return 0;
}