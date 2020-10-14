#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
int n;

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        double sum=0;
        for(int j=0; j<10; j++){
            int temp;
            cin>>temp;
            sum += temp;
        }
        cout<<"#"<<i+1<<" "<<round(sum/10)<<endl;
    }
}