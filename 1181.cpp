#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
vector<string> v;
bool comp(string s1, string s2){
    if(s1.size()==s2.size()) return s1<s2;
    else return s1.size()<s2.size();
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        char temp[55];
        scanf("%s", temp);
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), comp);

    cout<<v[0]<<endl;
    for(int i=1; i<n; i++){
        if(v[i]!=v[i-1]) cout<<v[i]<<endl;
    }
    
    return 0;
}