#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;
long long answer;
int arr[10] = {0,1,1,1,3,3,1,0,0};
set<int> s[55];

int dfs(int k){
    int num=0;
    

    for(int i=2; i<k-1; i++){
        num += dfs(i) + dfs(k-i);
    }
}



int solution(int k){
    s[2].insert(1);



    dfs(k);

    return answer;
}

void temp(set<int> &ss){
    ss.insert(2);
}

int main(){
    set<int> s;
    cout<<*s.begin()<<endl;
    temp(s);
    cout<<*s.begin()<<endl;
    



    // cout<<solution(5)<<endl;
    // cout<<solution(6)<<endl;
    // cout<<solution(11)<<endl;
    // cout<<solution(1)<<endl;
}