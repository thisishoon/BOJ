#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <iostream>

using namespace std;

unordered_map <string, int> m;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    set<string> s;
    for(int i=0; i<gems.size(); i++){
        s.insert(gems[i]);
    }
    int n = s.size();
    
    if(n==gems.size()){
        answer.push_back(1);
        answer.push_back(n);
        return answer;
    }
    
    vector<pair<int, int> > v;
    int len = gems.size();
    int left = 0;
    int right = 0;
    while(right < gems.size()) { 

        if(m.size() == n) { //어느 순간 답이 될 수 있는 경로를 찾아
            len = min(len, right - left);
            v.push_back({left, right});
        }
        if(m[gems[left]] >= 2) {    //두개를 들고있다는 뜻
            m[gems[left]]--;
            left++;
        }
        else {      //오른쪽을 늘려
            m[gems[right]]++;
            right++;
        }
    }
    
    while(1) {
        if(m[gems[left]] == 1) break;
        m[gems[left]]--;
        left++;
    }
    
    if(m.size() == n) {
        len = min(len, right - left);
        v.push_back({left, right});
    }
    

    for(int i = 0 ; i < v.size() ; ++i) {
        if(v[i].second - v[i].first == len) {
            answer.push_back(v[i].first + 1);
            answer.push_back(v[i].second);
            break;
        }
    }
    
    return answer;
}

int main(){
    vector<string> v;
    // v.push_back("DIA");
    // v.push_back("RUBY");
    // v.push_back("RUBY");
    // v.push_back("DIA");
    // v.push_back("DIA");
    // v.push_back("EMERALD");
    // v.push_back("DSAPPHIREIA");
    // v.push_back("DIA");
    v.push_back("XYZ");v.push_back("XYZ");v.push_back("XYZ");
    vector<int> answer = solution(v);
    cout<<answer[0]<<" "<<answer[1]<<endl;
}