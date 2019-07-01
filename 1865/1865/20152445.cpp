#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
int cost[505];

int main(){
    int tc;
    cin>>tc;
    for(int i=0; i<tc; i++){
        vector<pair<int,int>> v[505];    //vector가 매번 초기화되어야한다...
        int n,m,w;
        cin>>n>>m>>w;
        for(int i=0; i<m; i++){
            int a,b,c;
            cin>>a>>b>>c;
            v[a].push_back({b,c});
            v[b].push_back({a,c});
        }
        for(int i=0; i<w; i++){
            int a,b,c;
            cin>>a>>b>>c;
            v[a].push_back({b,-c});
        }
        for(int i=2; i<=n; i++){
            cost[i]=999999999;
        }
     
        bool result=false;
  
        for(int i=1; i<=n; i++){ //n번까지만 업데이트를 해보고 업데이트가 n번 발생하면 음수사이클이 존재하는 것
            for(int j=1; j<=n; j++){ //모든 점을 순회
                for(int k=0; k<v[j].size(); k++){
                    int next=v[j][k].first;
                    int next_cost=v[j][k].second;
                    if(cost[j]+next_cost < cost[next]){
                        cost[next]=cost[j]+next_cost;
                        if(i==n) {  //업데이트가 n번 발생
                            result=true;
                            break;
                        }
                    }
                }
            }
        }
        if(result==true) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
