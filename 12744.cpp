// #include <iostream>
// #include <algorithm>
// #include <queue>
// #include <vector>
// #include <string>
// #include <set>

#include <bits/stdc++.h>
using namespace std;
int n;

set<string> s;

struct node{
    int num[7];
    char direct[7];
    int count=0;
};

queue<node> q;

int main(){
    cin>>n;
    node init;
    string str="";
    for(int i=1; i<=n; i++){
        int a; char b;
        cin>>a>>b;
        init.num[i]=a;
        init.direct[i]=b;
        str+=(char)(a+48);
        str+=b;
    }
    s.insert(str);
    q.push(init);
    
    while(!q.empty()){
        node cur = q.front();
        q.pop();

        int flag=0;
        for(int i=1; i<=n; i++){   
            if(cur.num[i] != i || cur.direct[i] !='+'){
                flag=1;
                break;
            }
        }
        if(flag==0){    //성공
            cout<<cur.count<<endl;
            return 0;
        }

        for(int i=1; i<=n; i++){    //뒤집기
            node next;
            string str;
            for(int j=1; j<=i; j++){
                next.num[j]= cur.num[i+1-j];
                str += (char)(next.num[j]+48);
                if(cur.direct[i+1-j]=='+'){
                    next.direct[j]='-';
                    str += '-';
                }
                else{
                    next.direct[j]='+';
                    str += '+';
                } 
            }
            for(int j=i+1; j<=n; j++){
                next.num[j]=cur.num[j];
                next.direct[j]=cur.direct[j];
                str+= (char)(next.num[j]+48);
                str+= next.direct[j];
            }
            next.count = cur.count+1;
            if(s.end() == s.find(str)){
                s.insert(str);
                q.push(next);
            }
        }
    }
    return 0;
}