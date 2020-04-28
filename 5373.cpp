#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
char arr[6][9];

void test(){
    map <char, int> m;
    for(int i=0; i<6; i++){
        for(int j=0; j<9; j++){
            m[arr[i][j]]++;
        }
    }
    cout<<m['w']<<" "<<m['r']<<" "<<m['b']<<" "<<m['o']<<" "<<m['g']<<" "<<m['y']<<endl;
}

void prin(int a){
    for(int i=0; i<9; i++){
            cout<<arr[a][i];
            if(i==2 || i==5 || i==8) cout<<endl;
        }
}

void run(int n){
    char temp[9];
    temp[0]=arr[n][6]; temp[1]=arr[n][3]; temp[2]=arr[n][0];
    temp[3]=arr[n][7]; temp[4]=arr[n][4]; temp[5]=arr[n][1];
    temp[6]=arr[n][8]; temp[7]=arr[n][5]; temp[8]=arr[n][2];
    for(int i=0; i<9; i++) arr[n][i]=temp[i];

}

void func(char s){
    if(s=='U'){
        char a=arr[1][0]; char b=arr[1][1]; char c=arr[1][2];
        arr[1][0]=arr[2][0]; arr[1][1]=arr[2][1]; arr[1][2]=arr[2][2];
        arr[2][0]=arr[3][0]; arr[2][1]=arr[3][1]; arr[2][2]=arr[3][2];
        arr[3][0]=arr[4][0]; arr[3][1]=arr[4][1]; arr[3][2]=arr[4][2];
        arr[4][0]=a; arr[4][1]=b; arr[4][2]=c;
        run(0);
        
    }
    else if(s=='D'){
        char a=arr[1][6]; char b=arr[1][7]; char c=arr[1][8];
        arr[1][6]=arr[4][6]; arr[1][7]=arr[4][7]; arr[1][8]=arr[4][8];
        arr[4][6]=arr[3][6]; arr[4][7]=arr[3][7]; arr[4][8]=arr[3][8];
        arr[3][6]=arr[2][6]; arr[3][7]=arr[2][7]; arr[3][8]=arr[2][8];
        arr[2][6]=a; arr[2][7]=b; arr[2][8]=c;
        run(5);
    }
    else if(s=='F'){
        char a=arr[0][6]; char b=arr[0][7]; char c=arr[0][8];
        arr[0][6]=arr[4][8]; arr[0][7]=arr[4][5]; arr[0][8]=arr[4][2];
        arr[4][8]=arr[5][2]; arr[4][5]=arr[5][1]; arr[4][2]=arr[5][0];
        arr[5][2]=arr[2][0]; arr[5][1]=arr[2][3]; arr[5][0]=arr[2][6];
        arr[2][0]=a; arr[2][3]=b; arr[2][6]=c;
        run(1);        
    }
    else if(s=='R'){
        char temp[3]={arr[0][8], arr[0][5], arr[0][2]};
        arr[0][8]=arr[1][8]; arr[0][5]=arr[1][5]; arr[0][2]=arr[1][2];
        arr[1][8]=arr[5][8]; arr[1][5]=arr[5][5]; arr[1][2]=arr[5][2];
        arr[5][8]=arr[3][0]; arr[5][5]=arr[3][3]; arr[5][2]=arr[3][6];
        arr[3][0]=temp[0]; arr[3][3]=temp[1]; arr[3][6]=temp[2];
        run(2);
    }
    else if(s=='B'){
        char temp[3]={arr[0][2], arr[0][1], arr[0][0]};
        arr[0][2]=arr[2][8]; arr[0][1]=arr[2][5]; arr[0][0]=arr[2][2];
        arr[2][8]=arr[5][8]; arr[2][5]=arr[5][7]; arr[2][2]=arr[5][6];
        arr[5][8]=arr[4][6]; arr[5][7]=arr[4][3]; arr[5][6]=arr[4][0];
        arr[4][6]=temp[0]; arr[4][3]=temp[1]; arr[4][0]=temp[2];
        run(3);
    }
    else{
        char temp[3]={arr[0][0], arr[0][3], arr[0][6]};
        arr[0][0]=arr[3][8]; arr[0][3]=arr[3][5]; arr[0][6]=arr[3][2];
        arr[3][8]=arr[5][0]; arr[3][5]=arr[5][3]; arr[3][2]=arr[5][6];
        arr[5][0]=arr[1][0]; arr[5][3]=arr[1][3]; arr[5][6]=arr[1][6];
        arr[1][0]=temp[0]; arr[1][3]=temp[1]; arr[1][6]=temp[2];
        run(4);
    }
}


int main(){
    int t; cin>>t;
    while(t--){
        for(int i=0; i<9; i++){
            arr[0][i]='w';
            arr[1][i]='r';
            arr[2][i]='b';
            arr[3][i]='o';
            arr[4][i]='g';
            arr[5][i]='y';
        }
        int n; cin>>n;
        for(int i=0; i<n; i++){
            char a, b;
            cin>>a>>b;
            if(b=='+'){
                func(a);
            }
            else{
                func(a); //prin(0); prin(5); prin(4); cout<<"----"<<endl;
                func(a); //prin(0); prin(5); prin(4); cout<<"----"<<endl;
                func(a); //prin(0); prin(5); prin(4); cout<<"----"<<endl;
            }
            // for(int i=0; i<6; i++) prin(i);
            // cout<<"@@@@@@@@"<<endl;
        }
        prin(0);
        test();
    }


    return 0;
}