#include <iostream>
#include <algorithm>
#include <limits>
#include <queue>

priority_queue<int, vector<int>, greater<int> > pq;


using namespace std;
const int maxINT = 2100000000;
int n;
int arr[1001][4];
int dp[1001][4];
int answer = maxINT;

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=3; j++){
            cin>>arr[i][j];
        }
    }
    dp[1][1]=maxINT;
    dp[1][2]=maxINT;
    dp[1][3]=maxINT;

    for(int first=1; first<=3; first++){
        dp[1][first] = arr[1][first];

        for(int i=2; i<=n; i++){
            for(int j=1; j<=3; j++){
                dp[i][j] = maxINT;

                if(i==n && j==first) continue;

                for(int k=1; k<=3; k++){
                    if(j==k) continue;
                    dp[i][j] = min(dp[i][j], dp[i-1][k]+ arr[i][j]);
                }
            }
        }
        for(int last=1; last<=3; last++){
            answer = min(answer, dp[n][last]);
        }
        dp[1][first]=maxINT;
    }
    cout<<answer<<endl;
    

    



    return 0;
}