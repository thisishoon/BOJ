#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;
int arr[50];

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    int n = orders.size();
    for(int i=0; i<orders.size(); i++){
        sort(orders[i].begin(), orders[i].end());
    }
    for(int C=0; C<course.size(); C++){
        map<string, int> m;
        int len = course[C];
        for(int i=0; i<n; i++){
            int N = orders[i].size();
            if(len > N) continue;
            vector<int> temp;
            for(int i=0; i<len; i++) temp.push_back(1);
            for(int i=0; i<N-len; i++) temp.push_back(0);
            sort(temp.begin(), temp.end());
            do{
                string comb = "";
                for(int t=0; t<temp.size(); t++){
                    if(temp[t]==1) comb += orders[i][t];
                }
                m[comb]++;
            }
            while(next_permutation(temp.begin(), temp.end()));
            }   
            int mx = 0;
            for(auto it = m.begin(); it!=m.end(); it++){
                mx = max(mx, it->second);
            }
            cout<<mx<<endl;
            if(mx==1) continue;

            for(auto it = m.begin(); it!=m.end(); it++){
                if(it->second == mx){
                    if(len == it->first.size()) answer.push_back(it->first);
                } 
            }
    }


    sort(answer.begin(), answer.end());
    for(string str: answer) cout<<str<<" ";
    return answer;
}

int main(){
    vector<string> orders = {"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"};
    vector<int> course = {2,3,5};
    solution(orders, course);
}