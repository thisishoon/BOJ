#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
char input[51];
using namespace std;
stack<char> st;
int main(){

    char cmd; int first;
    int n;
    int minus=0;
    for(scanf("%d", &first); scanf("%c", &cmd), cmd!='\n';){
        scanf("%d", &n);
        if(cmd=='-')  minus = 1;
        if(minus) first-=n;
        else first+=n;
    }
    printf("%d",first);


    // int n;
    // string str;
    // cin>>str;
    // for(int i=0; i<str.length(); i++){
    //     st.push(str[i]);
    // }
    // int result=0;
    // int sum=0;
    // int stand=1;
    // while(!st.empty()){
    //     char temp = st.top();
    //     st.pop();
    //     if(temp=='-'){
    //         result-=sum;
    //         sum=0;
    //         stand=1;
    //     }
    //     if(temp=='+'){
    //         stand=1;
    //     }
    //     if('0'<=temp && temp<='9'){   
    //         sum += (stand*(temp-'0'));
    //         stand*=10;
    //     }
    // }
    // result+=sum;
    // cout<<result<<endl;

    return 0;
}