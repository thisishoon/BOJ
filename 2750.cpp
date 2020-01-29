#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

int arr[8008];
vector<int> v;

int main(){
    int n;
    double avg = 0;
    long long mx=-5000;
    long long mn=5000;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        int temp;
        scanf("%d", &temp);
        avg += temp;
        arr[temp+4000] +=1;
        if(mx<temp) mx=temp;
        if(mn>temp) mn=temp;
    }

    int range = round( (double)mx - double(mn) );

    int order=1;
    int center=0;
    int frequency=0;
    
    for(int i=0; i<=8000; i++){
        for(int j=0; j<arr[i]; j++){
            if(arr[i]==0) continue;
            else{
                
                if(order==((n+1)/2)){    //중앙값
                    center = i-4000;
                }
                order++;
            }
            
        }
        if(frequency<arr[i]){
                    frequency = arr[i];
                    v.erase(v.begin(), v.end());
                    v.push_back(i-4000);
                }
        else if(frequency==arr[i]){
            frequency = arr[i];
            v.push_back(i-4000);
            //cout<<i-4000<<"zzzz"<<endl;
        }
    }
    
    
    printf("%d\n", (int)round(avg/n));
    printf("%d\n", center);
    
    if(v.size()==1){
        printf("%d\n", v[0]);
    }
    else{
        printf("%d\n", v[1]);
    }

    printf("%d\n", range);
    






    return 0;
}