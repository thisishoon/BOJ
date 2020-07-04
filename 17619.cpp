#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, q;
int group[100001];
vector< pair< pair<int, int>, int> > v;
int main(){
    scanf("%d %d", &n, &q);
    for(int i=1; i<=n; i++){
        int a, b, c;    scanf("%d %d %d", &a, &b, &c);
        v.push_back(make_pair(make_pair(a,b), i));
    }
    sort(v.begin(), v.end());
    int g=1;
    group[v[0].second]=1;
    int left = v[0].first.first;
    int right = v[0].first.second;

    for(int i=1; i<v.size(); i++){
        if(v[i].first.first <= right){
            group[v[i].second]=g;
            right = max(right, v[i].first.second);
        }
        else{
            group[v[i].second]=++g;
            left = v[i].first.first;
            right = v[i].first.second;
        }
    }
    for(int i=0; i<q; i++){
        int a, b; scanf("%d %d", &a, &b);
        if(group[a]==group[b])  printf("1\n");
        else printf("0\n");
    }
    
    return 0;
}