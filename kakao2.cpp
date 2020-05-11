#include <string>
#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;
long long answer =0;
char op[3] = {'+','-','*'};
vector<string> v;

int priority[3];

vector<string> cal(vector<string> math, int oper){
    for(int i=0; i<math.size(); i++){
        if(oper==0){
            if(math[i]=="+"){
                int num = stoi(math[i-1]) + stoi(math[i+1]);
                math.insert(math.begin()+i-1, to_string(num));
                math.erase(math.begin()+i, math.begin()+i+3);
                i--;
            }
        }
        else if(oper==1){
             if(math[i]=="-"){
                int num = stoi(math[i-1]) - stoi(math[i+1]);
                math.insert(math.begin()+i-1, to_string(num));
                math.erase(math.begin()+i, math.begin()+i+3);
                i--;
            }
        }
        else{
             if(math[i]=="*"){
                int num = stoi(math[i-1]) * stoi(math[i+1]);
                math.insert(math.begin()+i-1, to_string(num));
                math.erase(math.begin()+i, math.begin()+i+3);
                i--;
            }
        }
    }
    return math;
}


void func(){
    for(int i=0; i<3; i++){
        vector<string> temp;
        temp.assign(v.begin(), v.end());
        vector<string> first = cal(temp, i);
        for(int j=0; j<3; j++){
            if(j==i) continue;
            vector<string> second = cal(first, j);
            for(int k=0; k<3; k++){
                if(k==i || k==j) continue;
                vector<string> third = cal(second, k);
                answer = max(answer, (long long)abs(stoi(third[0])));
            }
        }
    }
}

long long solution(string expression){
    v.clear();
    answer=0;
    string temp="";
    for(int i=0; i<expression.size(); i++){
        if(expression[i]>='0' && expression[i]<='9'){
            temp += expression[i];
            if(i==expression.size()-1) v.push_back(temp);
        }
        else{
            v.push_back(temp);
            temp="";
            v.push_back(string(1,expression[i]));
        }
    }
    
    func();
    cout<<answer<<endl;
    return answer;
}

int main(){
    string str = "100-200*300-500+20";
    solution(str);
    solution("50*6-3*2");
    return 0;
}