#include <iostream>
#include <vector>

using namespace std;

vector<string> split(string a, char split) {
	vector<string > p;
	int bef = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a.at(i) == split ) {
			if(bef != i )
				p.push_back(a.substr(bef, i-bef));
			bef = i+1;
		}
	}
	if (bef != a.size()) {
		p.push_back(a.substr(bef, a.size() - bef));
	}
	return p;
}


int main(){
    vector<string> result = split("09:04:39", ':');
    // for(string str:result){
    //     cout<<str<<" ";
    // }
	string str = "1";
	str+='0';
	str+=1;

	cout<<str;


    return 0;
}