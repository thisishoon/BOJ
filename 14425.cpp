#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main(){
    int n, m;
    int answer=0;
    cin>>n>>m;
    set<string> s;
    for(int i=0; i<n; i++){
        string str; cin>>str;
        s.insert(str);
    }
    for(int i=0; i<m; i++){
        string str; cin>>str;
        if(s.find(str)!=s.end()) answer++;
    }
    cout<<answer<<endl;


    return 0;
}