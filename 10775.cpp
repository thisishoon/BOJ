#include <iostream>
#include <algorithm>

using namespace std;
int answer;
int g, p;
int parent[100001];

int find(int x){
    if(parent[x]==x) return x;
    else return parent[x] = find(parent[x]);
}

int main(){
    cin>>g>>p;
    for(int i=1; i<=g; i++){
        parent[i] = i;
    }
    for(int i=1; i<=p; i++){
        int temp; scanf("%d", &temp);
        int flag = find(temp);
        if(flag!=0){
            parent[flag] = flag-1;
            answer++;
        }
        else    break;
    }
    cout<<answer<<endl;

    return 0;
}