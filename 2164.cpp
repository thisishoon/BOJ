#include <iostream>
#include <queue>
#include <deque>

using namespace std;
deque<int> de;

int main(){
    int n; cin>>n;
    for(int i=1; i<=n; i++){
        de.push_back(i);
    }
    while(de.size()!=1){
        de.pop_front();
        int temp = de.front();
        de.pop_front();
        de.push_back(temp);
    }
    cout<<de.front()<<endl;

    return 0;
}