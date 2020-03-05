#include <iostream>
#include <algorithm>

using namespace std;
int J[1011][1011];
int O[1011][1011];
int I[1011][1011];

int main(){
    int m, n, num;
    scanf("%d %d %d", &m, &n, &num);
    
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            char temp=0;
            cin>>temp;
            
            
            if(temp=='J'){
                J[i][j] = J[i-1][j] + J[i][j-1] - J[i-1][j-1] + 1;
                O[i][j] = O[i-1][j] + O[i][j-1] - O[i-1][j-1];
                I[i][j] = I[i-1][j] + I[i][j-1] - I[i-1][j-1];
            }
            else if(temp=='O'){
                J[i][j] = J[i-1][j] + J[i][j-1] - J[i-1][j-1];
                O[i][j] = O[i-1][j] + O[i][j-1] - O[i-1][j-1] +1;
                I[i][j] = I[i-1][j] + I[i][j-1] - I[i-1][j-1];
            }
            else if(temp=='I'){
                J[i][j] = J[i-1][j] + J[i][j-1] - J[i-1][j-1];
                O[i][j] = O[i-1][j] + O[i][j-1] - O[i-1][j-1];
                I[i][j] = I[i-1][j] + I[i][j-1] - I[i-1][j-1]+1;
            }
            // cout<<J[i][j]<<" ";
        }
        // cout<<endl;
    }
    for(int i=0; i<num; i++){
        int firstY, firstX, endY, endX;
        scanf("%d %d %d %d ", &firstY, &firstX, &endY, &endX);

        int a = J[endY][endX] - J[endY][firstX-1] - J[firstY-1][endX] + J[firstY-1][firstX-1];
        int b = O[endY][endX] - O[endY][firstX-1] - O[firstY-1][endX] + O[firstY-1][firstX-1];
        int c = I[endY][endX] - I[endY][firstX-1] - I[firstY-1][endX] + I[firstY-1][firstX-1];
        printf("%d %d %d\n", a, b, c);
    }
    return 0;
}