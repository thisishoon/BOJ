#include <iostream>
#include <string>
#include <vector>

using namespace std;

int soltion(vector<int> v){
    int answer=0;
    for(int i=1; i<v.size(); i++){
        int num = v[i];
        if(i%2==1){
            if(v[i-1] < v[i]) continue;
            else{
                answer++;
                v.insert(v.begin()+i, 11111);
            }
        }
        else{
            if(v[i-1]>v[i]) continue;
            else{
                answer++;
                v.insert(v.begin()+i, -11111);
            }
        }
    }
    return answer;
}

int main(){
    vector<int> temp;
    temp.push_back(3); temp.push_back(-1); temp.push_back(0); temp.push_back(4); 
    cout<<soltion(temp)<<endl;
    return 0;
}