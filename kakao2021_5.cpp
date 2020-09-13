#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdlib.h>

using namespace std;
int arr[1000000];
int play_n;
int adv_n;

int convertTime(string time){
    char str[1000];
    strcpy(str, time.c_str());
    char* tok = strtok(str, ":");
    int hour = atoi(tok);
    tok = strtok(NULL, ":");
    int min = atoi(tok);
    tok = strtok(NULL, ":");
    int sec = atoi(tok);
    int t = sec + min*60 + hour*60*60;
    return t;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    play_n = convertTime(play_time);
    adv_n = convertTime(adv_time);
    
    for(int i=0; i<logs.size(); i++){
        string log = logs[i];
        int idx=0;
        for(int j=0; j<log.size(); j++){
            if(log[j]=='-') idx = j;
        }
        int start = convertTime( log.substr(0, idx) );
        int finish = convertTime( log.substr(idx+1, -1) );
        for(int i=start; i<=finish; i++) arr[i]++;
    }
    int sum = 0;
    for(int i=0; i<=adv_n; i++){
        sum += arr[i];
    }
    int mx = sum;
    int idx = 0;

    for(int i=0; i<=play_n-adv_n; i++){
        sum -= arr[i];
        sum += arr[i+adv_n+1];
        if(mx<sum){
            mx=sum;
            idx=i+1;
        }
    }
    int hour = idx/3600;
    int min = (idx%3600)/60;
    int sec = (idx%3600)%60;
    if(hour/10 == 0) answer += ("0"+to_string(hour)+":");
    else answer += to_string(hour)+":";
    if(min/10 == 0) answer += ("0"+to_string(min)+":");
    else answer += to_string(min)+":";
    if(sec/10 == 0) answer += ("0"+to_string(sec));
    else answer += to_string(sec);

    
    cout<<answer;


    return answer;
}

int main(){
    string play_time = "02:03:55";
    string adv_time = "00:14:15";
    vector<string> logs = {"01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30"};
    solution(play_time, adv_time, logs);
}