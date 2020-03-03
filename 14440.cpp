#include <iostream>
#include <algorithm>
using namespace std;

struct matrix{
    int q0;
    int q1;
    int p0; 
    int p1;
};

matrix mul(matrix a, matrix b){
    matrix result;
    result.q0 = (a.q0 * b.q0 + a.q1 * b.p0)%100;
    result.q1 = (a.q0 * b.q1 + a.q1 * b.p1)%100;
    result.p0 = (a.p0 * b.q0 + a.p1 * b.p0)%100;
    result.p1 = (a.p0 * b.q1 + a.p1 * b.p1)%100;
    return result;
}

// matrix func(matrix a, int exp){
//     matrix result;
//     matrix base;
//     base.q0=1; base.q1=0; base.p0=0; base.p1=1;
//     while(exp){
//         cout<<exp<<endl;
//         if(exp%2) base = mul(base, a);
//         a = mul(a,a);
//         exp/=2;
//     }
//     return base;
// }

matrix func(matrix a, int exp){
    if(exp==1) return a;
    matrix half = func(a, exp/2);
    matrix result = mul(half, half);
    if(exp%2) result=mul(result, a);
    return result;
}

int main(){
    int x, y, a0, a1, n;
    cin>>x>>y>>a0>>a1>>n;
    if(n==0){
        cout<<a0<<endl;
        return 0;
    }
    else if(n==1){
        cout<<a1<<endl;
        return 0;
    }
    matrix m;
    m.q0 = 0; m.q1=1; m.p0=y; m.p1=x;
    matrix result = func(m, n-1);
    
    int temp = ((a0*result.p0) + (a1*result.p1)) %100;
    if(temp<10) cout<<"0"<<temp<<endl;
    else cout<<temp<<endl;
    
    return 0;
}