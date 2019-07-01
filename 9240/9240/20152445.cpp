#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int c;

struct point{
    long long x, y;
    bool operator<(point poi) const{ //기준점 구하기 용도
        if(this->x==poi.x) return this->y < poi.y;
        else return this->x < poi.x;
    }
    point operator-=(point poi){
        this->x-= poi.x; this->y-=poi.y; return *this;
    }
};
point p[100005];

point operator -(point a, point b){ return a-=b;}
long long operator *(point a, point b){ return a.x*b.x + a.y*b.y;}



//3점 비교
long long ccw(point &a, point &b, point &c){
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
//원점으로부터 2점 비교
bool compare(point &a, point &b){
    long long temp=ccw(p[1],a,b);
    
    if(temp>0) return 1; //시계방향
    else if(temp<0) return 0; //반시계방향
    else{ //일직선상에 있을 경우 벡터에 넣으면 안됌
        if(a.x==b.x) return a.y<b.y;
        else return a.x<b.x;
    }
}


int main(){
    scanf("%d", &c);
    for(int i=1; i<=c ; i++){
        scanf("%lld %lld",&p[i].x,&p[i].y);
    }
    
    sort(p+1, p+1+c);     //기준점 구하기
    sort(p+2, p+1+c, compare); //기준점에 맞춰 반시계방향으로 정렬
    
    vector<point> vec;
    vec.push_back(p[1]);
    vec.push_back(p[2]);
    
    for(int i=3; i<=c; i++){
        while(vec.size()>1 && ccw(p[vec.size()-1], vec.back(), p[i]) <=0 ){
            vec.pop_back();
        }
        vec.push_back(p[i]);
    }
    
    int len=int(vec.size());
    double result=-1;
    for(int i=0; i<=len/2; i++){
        for(int j=i+1; j<len; j++){
            result=max(result, sqrt((vec[i]-vec[j])*(vec[i]-vec[j])));
        }
    }
    
    
    printf("%.6f",result);
    
    
    return 0;
}




