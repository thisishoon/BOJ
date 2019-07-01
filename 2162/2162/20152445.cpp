#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
int n;
int groupNumber;
int maxSize;
struct point{
    int x;
    int y;
};

struct line{
    point a;
    point b;
};

line lines[3333];
int parent[3333];
int num[3333];

int ccw(point a,point b, point c){
    long long temp= (a.x*b.y+b.x*c.y+c.x*a.y)-(a.y*b.x+b.y*c.x+c.y*a.x);
    if(temp>0) return 1;
    else if(temp==0) return 0;
    else return -1;
}

int intersect(line line1, line line2){
    int temp1=ccw(line1.a,line1.b,line2.a) * ccw(line1.a,line1.b,line2.b);
    int temp2=ccw(line2.a,line2.b,line1.a) * ccw(line2.a,line2.b,line1.b);
    
    if(temp1==0&&temp2==0){    //일직선
        if(line1.a.x==line1.b.x){     //세로
            if(max(line1.a.y,line1.b.y)< min(line2.a.y,line2.b.y) || max(line2.a.y,line2.b.y)<min(line1.a.y,line1.b.y))return 0;
            else return 1;
        }
        else{   //대각선,가로
            if(max(line1.a.x,line1.b.x)< min(line2.a.x,line2.b.x) || max(line2.a.x,line2.b.x)<min(line1.a.x,line1.b.x))return 0;
            else return 1;
        }
    }
    if(temp1<=0 && temp2<=0) return 1;
    return 0;
}

int findParent(int child){
    if(parent[child]==child) return child;
    else return findParent(parent[child]);
}
void join(int a,int b){
    int a_parent=findParent(a);
    int b_parent=findParent(b);
    parent[b_parent]=a_parent;
}

int main(){
    int n;
    cin>>n;
    int x1,y1,x2,y2;
    
    for(int i=1; i<=n; i++){
        cin>>x1>>y1>>x2>>y2;
        lines[i].a.x=x1;
        lines[i].a.y=y1;
        lines[i].b.x=x2;
        lines[i].b.y=y2;
        parent[i]=i;
    }
    
    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++)
            if(intersect(lines[i],lines[j])) join(i, j);
    
    for(int i=1; i<=n; i++){
        if(num[findParent(i)]==0) groupNumber++;
        
        int temp= ++num[findParent(i)];
        maxSize=max(maxSize,temp);
    }
    
    cout<<groupNumber<<endl;
    cout<<maxSize<<endl;
    
    return 0;
}

