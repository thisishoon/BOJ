#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int n, l;
deque<pair<int, int> > de; //num, index 
int main(){
    cin>>n>>l;

    for(int i=1; i<=n; i++){
        int temp;
        scanf("%d", &temp);
        while(!de.empty() && de.front().second <= i-l){
            de.pop_front();
        }
        while(!de.empty() && de.back().first > temp){
            de.pop_back();
        }
        de.push_back(make_pair(temp, i));
        printf("%d ", de.front().first);
        
    }

    return 0;
}