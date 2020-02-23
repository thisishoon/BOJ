#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;
int main (){
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        int temp;
        cin>>temp;
        if(temp!=0) v.push_back(temp);
        else v.pop_back();
    }
    

    int result=0;
    for(int i=0; i<v.size(); i++){
        int temp = v[i];
        result += temp;
    }

    cout<<result;




    return 0;
}