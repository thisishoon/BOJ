#include <iostream>

using namespace std;

int arr[10]={1,1,1,1,1,1,1,1,1};

void func(int a[]){
    a[0]=999999999;
    a[3]=2222;
}

int main(){
    func(arr);
    

    cout<<arr[0]<<endl;
    cout<<arr[3]<<endl;
}