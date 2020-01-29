#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    int k = 1;

    while(k<=1000000){
        int i = k;
        int target = 0;
        target += i;
        while(1){
            target += i % 10;
            i /= 10;
            if(i==0) {
                break;
            }
        }
        if(target == n){
            cout<<k;
            return 0;
        }
        else
            k += 1;
    }
    
    cout<<"0"<<endl;
    return 0;
}
