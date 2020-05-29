#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
int arr[30010];
int n,d,k,c;
int answer = 0;
map<int, int> m;

int main(){
    cin>>n>>d>>k>>c;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<k; i++){
        m[arr[i]]++;
    }
    m[c]++;
    answer = m.size();

    for(int i=k; i<n+k-1; i++){
        m[arr[i-k]]--;
        if(m[arr[i-k]]==0) m.erase(arr[i-k]);
        m[arr[i%n]]++;
        answer = max(answer, (int)m.size());
    }
    
    cout<<answer<<endl;
    
    return 0;
}