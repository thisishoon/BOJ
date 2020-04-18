#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
int n, k;
queue<int> q[22]; 
long long answer;

int main(){
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        string temp; cin>>temp;
        int tempL = temp.length();
        q[tempL].push(i);
        while(!q[tempL].empty()){
            if(i-q[tempL].front() > k){
                q[tempL].pop();
            }
            else{
                answer += (q[tempL].size()-1);
                break;
            }
        }
    }
    cout<<answer<<endl;

    return 0;
}