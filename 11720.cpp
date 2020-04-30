#include <iostream>
using namespace std;

int main(){
    int n; cin>>n;
    int result=0;
    for(int i=1; i<=n; i++){
        // char c;
        // cin>>c;
        // result += (c-48);
        int num;
        scanf("%1d", &num);
        result+=num;
    }
    cout<<result<<endl;
    return 0;
}