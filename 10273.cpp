#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
int t,n,e;
int arr[20002];
long long dp[20002][2];
int input[20002];
int parent[20002];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>t;
    while(t--){
        memset(arr, 0, sizeof(arr));
        memset(input, 0, sizeof(input));
        //fill(dp, dp+20002, -2147483647);
        memset(parent, 0, sizeof(parent));
        vector<pair<int, int> > v[20002];
        queue<int> q;
        cin>>n>>e;
        for(int i=1; i<=n; i++){ 
            cin>>arr[i];
            dp[i][0]=-2147483647;
            dp[i][1]=0;
        }
        
        for(int i=1; i<=e; i++){
            int a, b, c;
            cin>>a>>b>>c;
            v[a].push_back(make_pair(b,c));
            input[b]++;
        }
        q.push(1);
        dp[1][0]=arr[1];
        dp[1][1]=1;
        parent[1]=0;
        for(int i=1; i<=n; i++){
        
            if(q.empty()) break;
            int here = q.front();
            q.pop();
            
            for(int j=0; j<v[here].size(); j++){
                int next = v[here][j].first;
                int nextCost = v[here][j].second;
                if(dp[next][0]<=dp[here][0]+arr[next]-nextCost){
                    dp[next][0] = dp[here][0]+arr[next]-nextCost;
                    dp[next][1] = dp[here][1]+1;
                    parent[next]=here;
                }
                input[next]-=1;
                if(input[next]==0) q.push(next);
            }
        }
        long long sum=-2147483647, depth=0;
        int end=0;
        for(int i=1; i<=n; i++){
            if(sum<dp[i][0]){
                end=i;
                sum=dp[i][0];
                depth=dp[i][1];
            } 
        }
        cout<<sum<<" "<<depth<<endl;
        stack<int> trace;
        for(int i=1; i<=n; i++){
            trace.push(end);
            end = parent[end];
            if(end<1) break;
        }
        for(int i=1; i<=depth; i++){
            int to = trace.top();
            cout<<to<<" ";
            trace.pop();
        }
        cout<<endl;
    }
    return 0;
}