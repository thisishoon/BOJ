#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
using namespace std;

/*
ip_addrs 벡터의 길이는 최대 100,000.
매번 순차 탐색하는 것은 시간이 오래걸린다고 판단.
동일한 IP주소에 따라 조건이 바뀌므로 map을 사용해서 동일한 IP갯수를 구했음.
1. map을 순회하면서 같은 IP주소로 접속한 학생이 4 이상이면 무조건 그 수를 더함
2. 3명이면, 세 명의 언어군이 같은지 판단해야함. C, C++, C#은 집단 언어군이고 이들의 공통점은 문자열의 첫 문자가 C라는 정보를 이용히여 판단
3. 2명이면, 두명의 점수를 판단하고 같은 언어군을 판단

map의 value 값으로 vector<int>를 사용한 이유 : 해당 IP주소를 가진 학생의 인덱스를 저장하여 2명과 3명인 상황에서 순차 탐색을 하지않고
인덱스로 즉시 조회하기 위해 사용하였음

*/

int solution(vector<string> ip_addrs, vector<string> langs, vector<int> scores){
    int answer=0;
    map<string,vector<int> > m;
    for(int i=0; i<ip_addrs.size(); i++){
        string ip = ip_addrs[i];
        m[ip].push_back(i);
    }
    for(auto it = m.begin(); it!=m.end(); it++){
        int s = it->second.size();
        if(s>=4) answer+=s;
        else if(s==3){
            int first = it->second[0];
            int second = it->second[1];
            int third = it->second[2];
            if(langs[first]==langs[second] && langs[second]==langs[third]){
                answer+=3;
                continue;
            }
            if(langs[first][0]=='C' && langs[second][0]=='C' && langs[third][0]=='C'){
                answer+=3;
                continue;
            }
        }
        else if(s==2){
            int first = it->second[0];
            int second = it->second[1];
            if(scores[first] == scores[second]){
                if(langs[first]==langs[second] || (langs[first][0]=='C'&&langs[second][0]=='C') ){
                    answer+=2;
                }
            }
        }
    }
    answer = ip_addrs.size()-answer;
    return answer;
}

int main(){
    vector<string> a;
    a.push_back("5.5.5.5");
    a.push_back("155.123.124.111");
    a.push_back("10.16.125.0");
    a.push_back("155.123.124.111");
    a.push_back("5.5.5.5");
    a.push_back("155.123.124.111");
    a.push_back("10.16.125.0");
    a.push_back("10.16.125.0");

    vector<string> b;
    b.push_back("Java");
    b.push_back("C++");
    b.push_back("Python3");
    b.push_back("C#");
    b.push_back("Java");
    b.push_back("C");
    b.push_back("Python3");
    b.push_back("JavaScript");
    vector<int> c;
    c.push_back(294);
    c.push_back(197);
    c.push_back(373);
    c.push_back(45);
    c.push_back(294);
    c.push_back(62);
    c.push_back(373);
    c.push_back(373);
    cout<<solution(a, b, c)<<endl;

    return 0;
}