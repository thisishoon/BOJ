#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
int arr[100011];
vector<char> v;
stack<int> st;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin>>n;
    for(int i=1; i<=n; i++) cin>>arr[i];
    int i=1; int num=1;

    while(i<=n){
        if(st.empty()){
            st.push(num++);
            v.push_back('+');
            //continue;
        }
        if(arr[i]>st.top()){
            st.push(num++);
            v.push_back('+');
        }
        else if(arr[i]==st.top()){
            i++;
            st.pop();
            v.push_back('-');
        }
        else{
            cout<<"NO\n";
            return 0;
        }
    }
    for(int i=0; i<v.size(); i++) cout<<v[i]<<'\n';

    return 0;
}