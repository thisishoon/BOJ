#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int chickenPrice, money, F, C;

int main(){
    int t; 
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d %d", &chickenPrice, &money, &F, &C);
        int vip, slave; //vip상언 slave두영
        int vipCoupon, slaveCoupon;
        int result;

        vip = slave = money/chickenPrice;
        vipCoupon = slaveCoupon = slave*C;
        slave += (slaveCoupon/F);

        int lastCoupon = (vipCoupon/F)*C + vipCoupon%F;
        
        if(lastCoupon>=F) result = (lastCoupon-F) / (F-C) + 1;  //미리 한개를 산다
        //result = (lastCoupon-C) / (F-C)  마지막은 쿠폰을 주지 않는다
        else result = 0;                   

        

        printf("%d\n", result);
    }
    return 0;
}