#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int comp(string a, string b){
    return a.size() < b.size();
}

int main(){
    int t; cin>>t;
    while(t--){
        string str[10001];
        map<string, int> m;

        int n; cin>>n;
        for(int i=0; i<n; i++){
            cin>>str[i];
        }
        sort(str, str+n, comp);
        m[str[0]]++;
        int flag=0;
        for(int i=1; i<n; i++){
            for(int j=1; j<=str[i].size(); j++){
                if(m[str[i].substr(0, j)]){
                    flag=1;
                    break;
                }
            }
            m[str[i]]++;
            if(flag){
                cout<<"NO"<<endl;
                break;
            }
        }
        if(!flag) cout<<"YES"<<endl;
    }

    return 0;
}