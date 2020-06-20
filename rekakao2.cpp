#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;



vector<string> cal(vector<string> v, int op){
    for(int i=0; i<v.size(); i++){
        if(op==0 && v[i]=="+"){
            int num = stoi(v[i-1]) + stoi(v[i+1]);
            v[i-1] = to_string(num);
            v.erase(v.begin()+i, v.begin()+i+2);
            i--;
        }
        else if(op==1 && v[i]=="-"){
            int num = stoi(v[i-1]) - stoi(v[i+1]);
            v.insert(v.begin()+i-1, to_string(num));
            v.erase(v.begin()+i, v.begin()+i+3);
            i--;
        }
        else if(op==2 && v[i]=="*"){
            int num = stoi(v[i-1]) * stoi(v[i+1]);
            v.insert(v.begin()+i-1, to_string(num));
            v.erase(v.begin()+i, v.begin()+i+3);
            i--;
        }
    }
    
    return v;
}


long long solution(string expression){
    vector<string> v;
    string temp="";
    for(int i=0; i<expression.size(); i++){
        if(expression[i]>='0' && expression[i]<='9'){
            temp += expression[i];
        }
        else{
            v.push_back(temp);
            v.push_back(string(1, expression[i]));
            temp="";
        }
        if(i==expression.size()-1){
            v.push_back(temp);
        }
    }
    
    int answer = 0;
    
    for(int i=0; i<3; i++){
        vector<string> init;
        init.assign(v.begin(), v.end());
        vector<string> first = cal(init, i);
        for(int j=0; j<3; j++){
            if(i!=j){
                vector<string> second = cal(first, j);
                for(int k=0; k<3; k++){
                    if(k!=i && k!=j){
                        vector<string> third = cal(second, k);
                        answer = max(answer, abs(stoi(third[0])));
                    }
                }
            }
        }
    }
    return answer;

}

int main(){
    cout<<solution("100-200*300-500+20")<<endl;
    cout<<solution("50*6-3*2");
}