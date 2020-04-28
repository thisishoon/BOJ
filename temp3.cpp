#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <string>
#include <map>
#include <set>

using namespace std;
pair<int, int> arr[300003];
pair<int, int> rel[300003];
int visited[300003];
int answer;
int main(){
    int n; int m;
    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>arr[i].first>>arr[i].second;
    
    for(int i=1; i<=m; i++){
        cin>>rel[i].first>>rel[i].second;
    }

    for(int i=1; i<=n; i++){
        set<int> s;
        s.insert(i);
        int flag=0;

        for(int j=1; j<=n; j++){
            if(visited[j]==1) continue;
            int a = rel[j].first;
            int b = rel[j].second;
            if(s.find(a) != s.end()){
                s.insert(b);
                visited[j]=1;
            }
            else if(s.find(b) != s.end()){
                s.insert(a);
                visited[j]=1;
            }
        }
        if(s.size()>1){
            int minY=111111111; int minX=111111111;   //최소
            int maxY=0; int maxX=0; //최대
            for(auto it=s.begin(); it!= s.end(); it++){
                int order = *it;
                int y = arr[order].first; int x = arr[order].second;
                minY = min(minY, y); minX = min(minX, x);
                maxY = max(maxY, y); maxX = max(maxX, x);
            }
            int power = (maxX-minX)*2 + (maxY-minY)*2;
            answer = max(answer, power);
        }
    }
    cout<<answer<<endl;



    return 0;
}