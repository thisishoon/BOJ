#include <iostream>

int blackjack[111];
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    int m;
    int result = 0;
    int temp = 0;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>blackjack[i];
    }
    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                temp = blackjack[i] + blackjack[j] + blackjack[k];
                if(result < temp)
                    if(temp<=m)
                        result = temp;
            }
        }
    }
    cout<<result;
    
    return 0;
}
