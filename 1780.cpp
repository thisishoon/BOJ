#include <iostream>
#include <algorithm>
using namespace std;
int arr[2200][2200];
int result[3];
void func(int y, int x, int n){
    int temp = arr[y][x];
    int third = n/3;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(temp!=arr[y+i][x+j]){
                for(int a=0; a<3; a++){
                    for(int b=0; b<3; b++){
                        func(y+third*a, x+third*b, third);
                    }
                }
                return;
            }
        }
    }
    result[++temp]++;
    return ;
}

int main(){
    int n; cin>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) scanf("%d", &arr[i][j]);

    func(1, 1, n);
    for(int i=0; i<3; i++)
        cout<<result[i]<<endl;

    return 0;
}