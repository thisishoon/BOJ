#include <iostream>
using namespace std;
int weight[100];
int height[100];

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>weight[i]>>height[i];
    }
    

    for(int i=0; i<n; i++){
        int order = 1;
        for(int j=0; j<n; j++){
            
            if(i==j) continue;
            else{
                if(weight[i] < weight[j]){
                    if(height[i] < height[j]){
                        order++;
                    }
                }
            }
        }
        cout<<order<<" ";
    }
    return 0;
}
