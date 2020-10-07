#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

int solution(vector<int> v){
    int result = 0;
    map<int, int> m;
    int left = 0;
    int right = 0;
    while(left <= right && right<v.size()){
        m[v[right]]++;
        if(m.size()<=2){
            right++;
        }
        else{
            result = max(result, right - left);
            while(m.size()>2 && left<=right){
                if(--m[v[left]] == 0){
                    m.erase(v[left]);
                }
                left++;
            }
            right++;
        }
    }
    result = max(result, right - left);
    
    return result;
}


int main(){
    
    vector<int> v = {4,5,5,4,5};
    cout<<solution(v)<<endl;
    v = {4,2,2,4,2};
    cout<<solution(v)<<endl;
    v = {1,2,3,2};
    cout<<solution(v)<<endl;
    v = {0,5,4,4,5, 12};
    cout<<solution(v)<<endl;
    v = {4, 4};
    cout<<solution(v)<<endl;
    v = {1,2,3,3,3,3,3,3,4,5,10,10,10,10,10};
    cout<<solution(v)<<endl;

    return 0;
}