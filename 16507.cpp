#include <iostream>
#include <algorithm>
using namespace std;

int arr[1111][1111];
int sum[1111][1111];

int main(){
    int r, c, q;
    // scanf("%d %d %d", r, c, q);
    cin>>r>>c>>q;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            scanf("%d", &arr[i][j]);
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j];
        }
    }
    
    for(int i=1; i<=q; i++){
        int r1, c1, r2, c2;
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    
        if( (r1==r2 && c1<c2) || (c1==c2 && r1<r2) || (r1<r2 && c1<c2) ){
            swap(r1,r2); swap(c1,c2);
        }
        
        int result = sum[r1][c1] - sum[r2-1][c1] - sum[r1][c2-1] + sum[r2-1][c2-1];

        result /=  ( (r1-r2+1)*(c1-c2+1) );
        printf("%d\n", result);
    }

    return 0;
}