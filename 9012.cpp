#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main(){
    int n;
    scanf("%d\n", &n);
    for(int i=1; i<=n; i++){
        stack<char> st;
        char c;
        int open=0;
        int close=0;
        for(; scanf("%c", &c), c!='\n'; ){
            st.push(c);
        }
        int s=st.size();
        for(int i=0; i<s; i++){
            char temp=st.top();
            st.pop();
            if(temp=='(') open++;
            else if(temp==')') close++;

            if(open>close) {
                printf("NO\n");
                break;
            }
        }
        //cout<<open<<" "<<close<<endl;
        if(open==close) printf("YES\n");
        else if(open<close) printf("NO\n");
    }


    return 0;
}