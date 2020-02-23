#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    int max = n*2-1;
    for(int i=1; i<=max; i++){
        int col=0;
        if(i>n) col=2*n-i;
        else col=i;
    
        for(int a=1; a<col; a++) cout<<" ";
        for(int j=col; j<=max+1-col; j++){
            cout<<"*";
        }
        //for(int c=max-col; c<=max; c++) cout<<" ";
        cout<<endl;
    }
    


    return 0;
}