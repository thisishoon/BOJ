#include <iostream>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <unordered_map>

using namespace std;
int n;
pair<int, int> arr[1000001];
int sum[1000001];
int answer;
unordered_map<int, int> m;

int comp(pair<int, int>a, pair<int, int> b){
    return a.second<b.second;
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int a, b; scanf("%d %d", &a, &b);
        arr[i]=make_pair(a,b);
    }
    sort(arr, arr+n, comp);

    sum[0]= arr[0].first==1? 1 : -1;
    for(int i=1; i<n; i++){
        if(arr[i].first==1) sum[i] = sum[i-1] + 1;
        else sum[i] = sum[i-1] + -1;

        if(sum[i]==0) answer = arr[i].second-arr[0].second;
    }
    

    for(int i=0; i<n; i++){
        if(m.find(sum[i])==m.end()){
            m[sum[i]]=i; 
        }
    }
    
    for(int i=n; i>=1; i--){
        if(m.find(sum[i])!=m.end()){
            if(m[sum[i]]!=i)
                answer = max(answer, arr[i].second- arr[m[sum[i]]+1].second);
        }

    }


    cout<<answer<<endl;
    
    

}