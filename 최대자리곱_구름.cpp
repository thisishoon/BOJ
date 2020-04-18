#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int func(int n){
	int result = 1;
	while(n!=0){
		result *= (n%10);
		n/=10;
	}
	return result;
}

using namespace std;
int main() {
	char input[100];
	cin >> input;
	int num = stoi(input);
	int result = func(num);
	
	for(int i=1, stand=1; i<strlen(input); i++, stand*=10){
		int temp = (num%(10*stand))+1;
		num -= temp;
		result = max(result, func(num));
	}

	cout<<result<<endl;
	
	return 0;
}