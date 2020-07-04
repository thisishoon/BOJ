#include <vector>
#include <string>
#include <iostream>

using namespace std;
int month[13]={0,31,28,31,30,31,30,31,30,31,30,31,30};
int day[366];

vector<string> splitByChar(string str, char ch){
    vector<string> result;
    int idx=0;
    for(int i=0; i<str.size(); i++){
        if(str[i]==ch){
            result.push_back(str.substr(idx, i-idx));
            idx = i+1;
        }
    }
    result.push_back(str.substr(idx, str.size()-idx));

    return result;
}

int switchDatetoDay(int m, int d){
    int result = 0;
    for(int i=1; i<m; i++){
        result += month[i];
    }
    result += d;
    return result;
}

vector<int> solution(vector<string> purchase) {
    vector<int> answer(5,0);
    for(int i=0; i<purchase.size(); i++){
        vector<string> firstResult = splitByChar(purchase[i], ' ');
        int money = stoi(firstResult[1]);
        vector<string> secondResult = splitByChar(firstResult[0], '/');
        int d = switchDatetoDay(stoi(secondResult[1]), stoi(secondResult[2]));
        day[d] = money;
    }    
    int sum=0;
    for(int i=1; i<=365; i++){
        sum += day[i];
        if(i-30 >= 1) sum -= day[i-30];

        if(sum < 10000) answer[0]++;
        else if(sum>=10000 && sum<20000) answer[1]++;
        else if(sum>=20000 && sum<50000) answer[2]++;
        else if(sum>=50000 && sum<100000) answer[3]++;
        else if(sum>=100000) answer[4]++;
    }
    



    return answer;
}
int main(){
    vector<string> v;
    v.push_back("2019/01/01 5000");
    v.push_back("2019/01/20 15000");
    v.push_back("2019/02/09 90000");
    vector<int> answer = solution(v);
    for(int i=0; i<answer.size(); i++){
        cout<<answer[i]<<" ";
    }

    cout<<day[365]<<" "<<day[20000]<<endl;
    
}