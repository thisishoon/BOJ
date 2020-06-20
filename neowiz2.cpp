#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> firstFunc(vector<string> v, int i){

    if(v[i+1]=="+"){
        int num = stoi(v[i]) + stoi(v[i+2]);
        string a = to_string(num);
        v.insert(v.begin()+i, a);
    }
    else if(v[i+1]=="-"){
        int num = stoi(v[i]) - stoi(v[i+2]);
        string a = to_string(num);
        v.insert(v.begin()+i, a);
    }
    else if(v[i+1]=="x"){
        int num = stoi(v[i]) * stoi(v[i+2]);
        string a = to_string(num);
        v.insert(v.begin()+i, a);
    }
    v.erase(v.begin()+i+1, v.begin()+i+4);
    return v;
}

long long solution(string str){
    long long answer=0;
    vector<string> v;

    for(int i=0; i<str.length(); i++){
        string a = string(1, str[i]);
        v.push_back(a);
    }
    for(int i=0; i<v.size()-1; i+=2){

        vector<string> temp;
        temp.assign(v.begin(), v.end());

        vector<string> first = firstFunc(temp, i);
        for(int j=0; j<first.size(); j++){
            cout<<first[j]<<" ";
        }
        cout<<endl;
    }
    


    
    return answer;
}

int main(){
    string str = "2-1x5-4x3+2";
    cout<<solution(str);
    return 0;
}