#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <string>

using namespace std;
int arr[100001];

int main(){
    int n;
    cin>>n;
    for(int i=1; i<=n; i++) cin>>arr[i];
    int answer=0;
    for(int width=1; width<=n; width++){
        int temp=0;
        for(int i=1; i<=n; i++){
            int temp=0;
            for(int j=i; j<i+width; j++){
                if(j>n) break;
                temp += arr[j];
            }
            answer = max(answer, temp);
        }
    }
    cout<<answer<<endl;


    return 0;
}