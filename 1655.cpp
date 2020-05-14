#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;
int n;
priority_queue<int, vector<int>, less<int> > max_heap;
priority_queue<int, vector<int>, greater<int> > min_heap;

int main(){
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++){
        int temp; scanf("%d", &temp);
        if(max_heap.empty()){
            max_heap.push(temp);
        }
        else if(max_heap.size() == min_heap.size()){
            max_heap.push(temp);
        }
        else{
            min_heap.push(temp);
        }
        if(!max_heap.empty() && !min_heap.empty()){
            if(max_heap.top() > min_heap.top()){
                int a = max_heap.top();
                int b = min_heap.top();
                max_heap.pop(); min_heap.pop();
                max_heap.push(b); min_heap.push(a);
            }
        }

        if(i%2==0){
            printf("%d\n", max_heap.top());
        }
        else
            printf("%d\n", max_heap.top());
    }


    return 0;
}