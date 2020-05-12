#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <deque>

using namespace std;
int arr[3000010];
int n,d,k,c;
int answer = 0;
map<int, int> m;
deque<int> de;

int main(){
    cin>>n>>d>>k>>c;
    for(int i=0; i<k; i++){
        int temp; cin>>temp;
        de.push_back(temp);
        m[temp]++;
    }
    m[c]++;

    answer = m.size();
    for(int i=k; i<n+k-1; i++){
        int temp; cin>>temp;
        de.push_back(temp);
        m[temp]++;
        int first = de.front();
        de.pop_front();
        if(--m[first]==0) m.erase(first);
        answer = max(answer, (int)m.size());
    }
    cout<<answer<<endl;
    
    return 0;
}