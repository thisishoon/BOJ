#include <iostream>

using namespace std;
int parent[1000001];

int find(int x){
    if(x==parent[x]) return x;
    else return parent[x] = find(parent[x]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a!=b) parent[a]=b;
}

int main(){
    int n, m; scanf("%d %d", &n, &m);
    for(int i=0; i<=n; i++) parent[i] = i;

    for(int i=1; i<=m; i++){
        int op, a, b; 
        scanf("%d %d %d", &op, &a, &b);

        if(op==0){
            merge(a,b);
        }
        else if(op==1){
            if(find(a)==find(b)) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}