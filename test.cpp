// you can use includes, for example:
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    string str = "";
    while(N){
        int temp = N % 2;
		N = N/2;
        str += to_string(temp);
    }
	reverse(str.begin(), str.end());
    
    int result = 0;
    int answer = 0;
	cout<<str<<endl;
	
    for(int i=0; i<str.size(); i++){
        if(str[i]=='0'){
            result++;
            
        }
        else{
            answer = max(answer, result);
            result = 0;
        }
    }
    return answer;
}

int main(){
	if(-1){
        cout<<"@";
    }
}
