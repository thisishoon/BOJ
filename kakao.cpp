#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

long long ans;
vector<string> numAndOper;

void parseExpressionString(string expression) {
    long long numberIdx = -1;
    for(long long i = 0 ; i < expression.size() ; ++i ) {
        if('0' <= expression[i] && expression[i] <= '9') {
            if(numberIdx == -1) numberIdx = i;
        }
        else { 
            numAndOper.push_back(expression.substr(numberIdx, i - numberIdx));
            numberIdx = -1;
            string temp = "";
            temp += expression[i];
            numAndOper.push_back(temp);
        }
    }
    numAndOper.push_back(expression.substr(numberIdx, expression.size() - numberIdx));
}

vector<string> cal(vector<string> expression, long long priority) {
    switch(priority) {
        case 0:
            for(int i = 0 ; i < expression.size() ; ++i) {
                if(expression[i] == "+") {
                    long long pre = stoll(expression[i - 1]);
                    long long next = stoll(expression[i + 1]);
                    long long result = pre + next;
                    expression.erase(expression.begin() + i - 1, expression.begin() + i + 2);
                    expression.insert(expression.begin() + i - 1, to_string(result));
                    i = 0;
                }
            }
            break;
            
        case 1:
            for(int i = 0 ; i < expression.size() ; ++i) {
                if(expression[i] == "-") {
                    long long pre = stoll(expression[i - 1]);
                    long long next = stoll(expression[i + 1]);
                    long long result = pre - next;
                    expression.erase(expression.begin() + i - 1, expression.begin() + i + 2);
                    expression.insert(expression.begin() + i - 1, to_string(result));
                    i = 0;
                }
            }
            break;
            
        case 2:
            for(int i = 0 ; i < expression.size() ; ++i) {
                if(expression[i] == "*") {
                    long long pre = stoll(expression[i - 1]);
                    long long next = stoll(expression[i + 1]);
                    long long result = pre * next;
                    expression.erase(expression.begin() + i - 1, expression.begin() + i + 2);
                    expression.insert(expression.begin() + i - 1, to_string(result));
                    i = 0;
                }
            }
            break;
    }
    return expression;
}

void findMaxValue() {
    for(int i = 0 ; i < 3 ; ++i) {
        vector<string> firstResult = cal(numAndOper, i);
        for(int j = 0 ; j < 3 ; ++j) {
            if(i == j) continue;
            vector<string> secondResult = cal(firstResult, j);
            for(int k = 0 ; k < 3 ; ++k) {
                if(k == i || k == j) continue;
                vector<string> thirdResult = cal(secondResult, k);

                if(abs(stoll(thirdResult[0])) > ans)
                    ans = abs(stoll(thirdResult[0]));
            }
        }
    }
}

long long solution(string expression) {
    parseExpressionString(expression);
    
    // 모든 연산자 우선순위를 고려함
    findMaxValue();
    cout<<ans<<endl;
    long long answer = ans;
    return answer;
}