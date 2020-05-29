#include <iostream>
#include <vector>

using namespace std;
int n, m;
int parent[222];

int find(int x){
    if(x==parent[x]) return x;
    else return parnet[x] = find(parent[x]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a!=b) parent[b]=a;
}

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++) parent[i]=i;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int temp; cin>>temp;
            if(temp)  merge(i,j);  
        }
    }
    int p;
    int flag=1;
    for(int i=1; i<=m; i++){
        int temp; cin>>temp;
        if(i==1) p = find(temp);
        if(p != find(temp)){
            flag=0;
            break;
        }
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    


    return 0;
}