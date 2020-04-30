#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
    string str; cin>>str;
    int answer=0;
    for(int i=0; i<str.length(); i++){
        char c = str[i];
        int order = c-'A';
        // cout<<order<<"!";
        if(order>=22) answer+= 10;
        else if(order>=19) answer+=9;
        else if(order>=15) answer+=8;
        else    answer += (order/3+3);
    }
    cout<<answer<<endl;
    return 0;
}