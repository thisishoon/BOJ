#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    while(1){
        int small_open=0;
        int small_close=0;
        int large_open=0;
        int large_close=0;
        stack<char> st;
        stack<char> st2;
        string str;
        getline(cin, str);
        if(str.length()==1 && str.compare(".")==0) break;

        for(int i=0; i<str.length(); i++){
            if(str[i]=='['||str[i]=='('||str[i]==']'||str[i]==')'){
                st.push(str[i]);
            }
        }
        int s = st.size();
        for(int i=0; i<s; i++){
            char temp = st.top();
            st.pop();
            if(st2.empty()) st2.push(temp);
            else{
                //cout<<temp<<" "<<st2.top()<<endl;
                if((temp=='(' && st2.top()==')')||(temp=='[' && st2.top()==']')){
                    st2.pop();
                }
                else{
                    st2.push(temp);
                }
            }
        }
        //cout<<st.size()<<" "<<st2.size()<<endl;
        if(st.size()==0 && st2.size()==0) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}