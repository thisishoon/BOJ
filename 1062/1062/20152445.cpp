#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string.h>
using namespace std;
int n, k, result;
bool chk[30];
char input[51][16];

int test(){
    int text=0;
    for(int i=0; i<n; i++){
        bool flag=true;
        for(int j=0; j<strlen(input[i]); j++){
            if(chk[input[i][j]-'a']==false){
                flag=false;
                break;
            }
        }
        if(flag==true) text++;
    }
    result=max(result,text);
    return 0;
}

void dfs(int index, int count){
    if(count==k) {
        test();                        //다 배웠을 경우
        return;
    }
    else{
        for(int i=index; i<26; i++){   //26 C k
            if(chk[i]==true) continue; //21 C k-5
            chk[i]=true;               //배우고
            dfs(i, count+1);           //탐색 후
            chk[i]=false;              //되돌아오기
        }
    }
}


int main(){
    cin>>n>>k;
    //a n t i c 는 무조건 배운다고 가정
    if(k<5){
        cout<<0<<endl;
        return 0;
    }
    else if(k==26){
        cout<<n<<endl;
        return 0;
    }
    else{
        k=k-5;
        chk['a'-'a']=chk['n'-'a']=chk['t'-'a']=chk['i'-'a']=chk['c'-'a']=true;
        for(int i=0; i<n; i++){
            char c[16];
            cin>>c;
            for(int j=0; j<strlen(c)-8; j++)
                input[i][j]=c[j+4];
        }
    }
    
    dfs(0,0);
    cout<<result<<endl;
    
    return 0;
}


