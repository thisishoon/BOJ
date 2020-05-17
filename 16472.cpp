#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
int n;
deque<char> de;
string str;
int answer;
map<char, int> m;

int main(){
    cin>>n>>str;
    int cnt=0;
    for(int i=0; i<str.length(); i++){
        cnt++;
        char c = str[i];
        de.push_back(c);
        m[c]++;
        while(m.size()>n){
            char temp = de.front();
            de.pop_front();
            m[temp]--;
            cnt--;
            if(m[temp]==0) m.erase(temp);
        }
        answer = max(answer, cnt);
    }
    cout<<answer<<endl;

    return 0;
}