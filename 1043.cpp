#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>

using namespace std;
int n,m;
int person[55];
int knowPerson;
vector<int> v[55];
int answer;
set<int> s;

int main(){
    cin>>n>>m;
    cin>>knowPerson;
    for(int i=1; i<=knowPerson; i++){
        int temp; cin>>temp;
        s.insert(temp);
    }
    for(int i=1; i<=m; i++){
        int temp; cin>>temp;
        for(int j=1; j<=temp; j++){
            int p; cin>>p;
            v[i].push_back(p);
        }
    }    
    while(1){
        int flag = 1;
        for(int i=1; i<=m; i++){
            for(int j=0; j<v[i].size(); j++){
                if(s.find(v[i][j]) != s.end()){
                    for(int k=0; k<v[i].size(); k++){
                        s.insert(v[i][k]);
                        flag=0;
                    }
                    v[i].clear();
                    break;
                }
            }
        }
        if(flag==1) break;
    }
    int result = m;

    for(int i=1; i<=m; i++){
        if(v[i].size()==0) result--;
    }
    cout<<result<<endl;

    return 0;
}