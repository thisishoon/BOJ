#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <limits.h>

using namespace std;
vector<int> v;


int check(string a, string b){
    int n;
    if(a.size()<b.size()) n = a.size();
    else n = b.size();
    for(int i=0; i<n; i++){
        if(a[i] != b[i]) return a[i]<b[i];
    }
    return a.size() < b.size();
}

int main(){
    string a = "aaaaaaa";
    string b = "cccc";

    cout<< check(a,b)<<endl;;
    cout<< (a<b)<<endl;


    return 0;
}