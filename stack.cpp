#include <iostream>
#include <stack>

using namespace std;

stack<int> s1;
stack<int> s2;

void _push(int num){
    s1.push(num);
}

int _pop2(){
    if(s2.size()==0){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int result = s2.top();
        s2.pop();
        return result;
    }
    else{
        int result = s2.top();
        s2.pop();
        return result;
    }
}

int _pop(){
    while(s1.size()!=1){
		int temp = s1. top();
		s2.push(temp);
		s1.pop();
	}
	int result = s1.top();
	s1.pop();

	while(s2.size()!=0){
		s1.push(s2.top());
		s2.pop();
	}
	return result;
}

int main(){
    _push(1);
    _push(2);
    _push(3);
    _push(4);
    cout<<_pop()<<endl;
    cout<<_pop()<<endl;
    _push(5);
    cout<<_pop()<<endl;
    cout<<_pop()<<endl;
    cout<<_pop()<<endl;



    return 0;
}