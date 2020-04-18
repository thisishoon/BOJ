#include <iostream>
#include <vector>
using namespace std;
vector<int> v[10];

#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>
#include <set>
#include <iostream>



using namespace std;


int main(){
    string temp = "abd def gggg ggggg gggg";
    char str[20];
    strcpy(str, temp.c_str());
    char* ptr = strtok(str, " ");
    set<string> s;
    while(ptr != NULL){
        s.insert(ptr);
        ptr = strtok(NULL, " ");
    }
    for(auto it : s){
        cout<<it<<endl;
    }
    vector<int> v;
    v.push_back(1); v.push_back(3000); v.push_back(2);
    sort(v.begin(), v.end());
    for(auto it : v){
        cout<<it<<endl;
    }
    
}