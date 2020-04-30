#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n;  cin>>n;
        string str; cin>>str;
        for(int i=0; i<str.length(); i++){
            for(int j=0; j<n; j++){
                cout<<str[i];
            }
        }
        cout<<endl;
    }

    return 0;
}