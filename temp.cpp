#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <string>
#include <map>
#include <bitset>

using namespace std;

struct st{
    string lang;
    string type;
    string old;
    string food;
    int score;
};
st arr[50005];


map<string, vector<int> > mlang;
map<string, vector<int> > mtype;
map<string, vector<int> > mold;
map<string, vector<int> > mfood;
map<int, vector<int> > mscore;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    for(int i=0; i<info.size(); i++){
        char str[1000];
        strcpy(str, info[i].c_str());
        char* tok = strtok(str, " ");
        string lang = tok;
        tok = strtok(NULL, " ");
        string type = tok;
        tok = strtok(NULL, " ");
        string old = tok;
        tok = strtok(NULL, " ");
        string food = tok;
        tok = strtok(NULL, " ");
        int score = stoi(tok);
        arr[i] = {lang, type, old, food, score};
        mlang[lang].push_back(i);
        mtype[type].push_back(i);
        mold[old].push_back(i);
        mfood[food].push_back(i);
        mscore[score].push_back(i);

    }
    for(int i=0; i<query.size(); i++){
        char str[1000];
        strcpy(str, query[i].c_str());
        char* tok = strtok(str, " ");
        string lang = tok;
        tok = strtok(NULL, " ");
        tok = strtok(NULL, " ");
        string type = tok;
        tok = strtok(NULL, " ");
        tok = strtok(NULL, " ");
        string old = tok;
        tok = strtok(NULL, " ");
        tok = strtok(NULL, " ");
        string food = tok;
        tok = strtok(NULL, " ");
        int score = stoi(tok);
        int visited[50005];
        memset(visited, 0, info.size()*sizeof(int));

        int num=0;
        int temp=1;
        int n = info.size();

        if(lang!="-"){
            for(int i=0; i<n; i++){
                if(lang!=arr[i].lang) visited[i]=1;
            }
        }
        if(type!="-"){
            for(int i=0; i<n; i++){
                if(visited[i]) continue;
                if(type!=arr[i].type) visited[i]=1;
            }
        }
        if(old!="-"){
            for(int i=0; i<n; i++){
                if(visited[i]) continue;
                if(old!=arr[i].old) visited[i]=1;
            }
        }
        if(food!="-"){
            for(int i=0; i<n; i++){
                if(visited[i]) continue;
                if(food!=arr[i].food) visited[i]=1;
            }
        }
        for(int i=0; i<n; i++){
            if(visited[i]) continue;
            if(score > arr[i].score) visited[i]=1;
        }

        for(int i=0; i<n; i++){
            if(visited[i]==0) num++;
        }
        
        // if(lang!="-"){
        //     vector<int> v = mlang[lang];    for(int i : v) arr[i]++;
        //     temp++;
        // }
        // if(type!="-"){
        //     vector<int> v = mtype[type]; for(int i: v) arr[i]++;
        //     temp++;
        // }
        // if(old!="-"){
        //     vector<int> v = mold[old]; for(int i:v) arr[i]++;
        //     temp++;
        // }
        // if(food!="-"){
        //     vector<int> v = mfood[food]; for(int i:v) arr[i]++;
        //     temp++;
        // }
        
        // for(auto it = mscore.begin(); it!=mscore.end(); it++){
        //     if(it->first >= score){
        //         for(int i : it->second){
        //             arr[i]++;
        //         }
        //     }
        // }
        
        
    

        
        answer.push_back(num);
    }


    for(int i : answer)cout<<i<<" ";
    return answer;
}



int main(){
    vector<string> info = {"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"};
    vector<string> query = {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};
    solution(info, query);

    string temp = "00001";
    string temp2 = "00011";
    int n = 5;
    auto result = bitset<n>(temp) & bitset<n>(temp2);
    cout<<result;

    return 0;
}