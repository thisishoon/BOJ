#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack<int> st;

int main(){
    int n;
    cin>>n;
    string str;
    int num, flag;
    for(int i=1; i<=n; i++){
        cin>>str;
        if(str.compare("push")==0){
            flag=1;
            cin>>num;
            st.push(num);
        }
        else if(str.compare("pop")==0){
            if(st.empty()) cout<<"-1"<<endl;
            else{
                int temp = st.top();
            st.pop();
            cout<<temp<<endl;
            }
        }
        else if(str.compare("size")==0){
            cout<<st.size()<<endl;
        }
        else if(str.compare("empty")==0){
            cout<<st.empty()<<endl;
        }
        else if(str.compare("top")==0){ 
            if(st.empty()) cout<<"-1"<<endl;
            else{
                int temp = st.top();
                cout<<temp<<endl;
            }
        }
    } 
    



    return 0;
}