
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    int result = 0;
    cin>>n;
    int num=1;
    
    while(1){
        int temp = num;
        int flag = 0;
        while(temp!=0){
            if(temp%1000==666){
                flag = 1;
                break;
            }
            else{
                temp/=10;
            }
        }
        if(flag){
            result++;
        }
        if(result==n){
            cout<<num;
            break;
        }
        
        num++;
    }
    
    return 0;
}
