#include <iostream>
#include <algorithm>
using namespace std;
int n, b, c;
long long result;
int arr[1000002];
int main(){

    // cin>>n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &arr[i]);
    scanf("%d %d", &b, &c);
    // cin>>b>>c;
    for(int i=1; i<=n; i++){
        result++;
        arr[i]-=b;
        if(arr[i]>0){
            int temp = (arr[i]/c);
        if(arr[i]==temp*c){
            result+=temp;
        }
        else result+=(temp+1);
        }
    }
    printf("%llu\n", result);
    return 0;
}
