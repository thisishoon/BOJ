#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(pair<int, string> a, pair<int, string> b){
    return a.first<b.first;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<string> v[200002];
    for(int i=0; i<n; i++){
        int temp1;
        string temp2;
        cin>>temp1>>temp2;
        v[temp1].push_back(temp2);
    }
    for(int i=1; i<=100000; i++){
        for(int j=0; j<v[i].size(); j++){
            cout<<i<<" "<<v[i][j]<<'\n';
        }
    }

    return 0;
}