#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
int n;
vector<int> v;
deque<int> de;
int visited[4000004];
int answer;
int sum;
int main(){
    cin>>n;
    for(int i=2; i<=n; i++){
        if(visited[i]==1) continue;
        v.push_back(i);
        for(int j=i; j<=n; j+=i){
            visited[j]=1;
        }
    }


    for(int i=0; i<v.size(); i++){
        de.push_back(v[i]);
        sum+= v[i];
        while(sum > n){
            sum -= de.front();
            de.pop_front();
        }
        if(sum == n) answer++;
    }
    cout<<answer<<endl;
    
    

    return 0;
}