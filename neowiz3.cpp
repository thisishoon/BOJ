#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;
int visited[100001];

int solution(vector<int> v){
    int answer=0;
    int n = v.size();
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++){
        if(visited[i]) continue;
        int pre = v[i];
        visited[i]=1;

        for(int j=i+1; j<n; j++){
            int next = v[j];
            if(pre < next && visited[j]==0){
                answer++;
                pre=next;
                visited[j]=1;
            }
        }
    }
    return answer;
}

int main(){
    vector<int> temp;
    temp.push_back(103);
    temp.push_back(101);
    temp.push_back(103);
    temp.push_back(103);
    temp.push_back(101);
    temp.push_back(102);
    temp.push_back(100);
    temp.push_back(100);
    temp.push_back(101);
    temp.push_back(104);


    cout<<solution(temp)<<endl;

}