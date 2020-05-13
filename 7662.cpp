#include <iostream>
#include <queue>
#include <deque>
#include <limits.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
priority_queue<long long, vector<long long>, less<long long> > pq1;   //큰게 나옴
priority_queue<long long, vector<long long>, greater<long long> > pq2;    //작은게나옴

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin>>t;
    while(t--){
        multiset<int> ms;
        int k; cin>>k;
        for(int i=0; i<k; i++){
            char c; cin>>c;
            if(c=='D'){
                int flag;   cin>>flag;
                if(flag==1){
                    if(ms.size()==0) continue;
                    auto it = ms.end();
                    it--;
                    ms.erase(it);
                }
                else if(flag==-1){
                    if(ms.size()==0) continue;
                    ms.erase(ms.begin());
                }
            }
            else if(c=='I'){
                long long I; cin>>I;
                ms.insert(I);
            }
        }

        if(ms.empty())   cout<<"EMPTY"<<endl;
        else{
            auto end = ms.end();
            end--;
            cout<<*(end)<<" "<<*ms.begin()<<endl;
        }
    }
    return 0;
}