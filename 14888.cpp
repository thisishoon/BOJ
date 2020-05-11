#include <iostream>
#include <algorithm>
using namespace std;

int arr[15];
int n;
int a, b, c, d;
int mn=999999999; 
int mx=-999999999;
int result=0;

int backtrack(int cnt){
    if(cnt==n-1){
        if(mx<result) mx=result;
        if(mn>result) mn=result;
        return 0;
    }
    if(a>0){
        result += arr[cnt+1];
        a--;
        backtrack(cnt+1);
        a++;
        result -= arr[cnt+1];
    }
    if(b>0){
        result -= arr[cnt+1];
        b--;
        backtrack(cnt+1);
        b++;
        result += arr[cnt+1];
    }
    if(c>0){
        int temp = result;
        result *= arr[cnt+1];
        c--;
        backtrack(cnt+1);
        c++;
        result = temp;
    }
    if(d>0){
        int temp = result;
        result /= arr[cnt+1];
        d--;
        backtrack(cnt+1);
        d++;
        result = temp;
    }
    return 0;
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int temp;
        scanf("%d", &temp);
        arr[i]=temp;
    }
    cin>>a>>b>>c>>d;
    result = arr[0];
    backtrack(0);
    cout<<mx<<endl<<mn<<endl;

    return 0;
}