#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <deque>

using namespace std;
int n,d,k,c;
int answer = 0;
map<int, int> m;
deque<int> de;
int arr[3003];
int kind[3000003];
int cnt;
int main(){
    scanf("%d %d %d %d", &n, &d, &k, &c);

    kind[c]=1;
    cnt=1;
    
    for(int i=0; i<k; i++){
        scanf("%d", &arr[i]);
        de.push_back(arr[i]);
        kind[arr[i]]++;
        if(kind[arr[i]]==1) cnt++;
    }
    

    answer = cnt;

    for(int i=k; i<n+k-1; i++){
        int temp; 
        if(i<n){
            scanf("%d", &temp);
        }
        else temp = arr[i%n];
        de.push_back(temp);
        if( (++kind[temp]) == 1 ) cnt++;

        if(  (--kind[de.front()]) == 0) cnt--;
        de.pop_front();
        answer = max(answer, cnt);
    }

    printf("%d\n", answer);
    
    return 0;
}