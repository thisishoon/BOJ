#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int arr[15];
int n;
int op[4];
char opc[4] = {'+', '-', '*', '/'};
int mn=999999999; 
int mx=-999999999;
int result=0;
string str;
vector<string> v;

int check(){
    vector<string> temp;
    temp.assign(v.begin(), v.end());
    int result=stoi(v[0]);
    for(int i=1; i<temp.size(); i++){
        if(temp[i]=="+"){
            result += stoi(temp[i+1]);
        }
        else if(temp[i]=="-"){
            result -= stoi(temp[i+1]);
        }
    }

    mn = min(mn, result);   mx = max(mx, result);
    return 0;
}

int backtrack(int cnt){
    if(cnt==n-1){
        int temp = check();
        return 0;
    }

    for(int i=0; i<4; i++){
        if(op[i]>0){
            op[i]--;
            if(i==2){
                string temp = v.back();
                int num = stoi(v.back()) * arr[cnt+1];
                v.pop_back();
                v.push_back(to_string(num));
                backtrack(cnt+1);
                v.pop_back();
                v.push_back(temp);
                op[i]++;
            }
            else if(i==3){
                string temp = (v.back());
                int num = stoi(v.back()) / arr[cnt+1];
                v.pop_back();
                v.push_back(to_string(num));
                backtrack(cnt+1);
                v.pop_back();
                v.push_back(temp);
                op[i]++;
            }
            else{
                v.push_back(string(1, opc[i]));
                v.push_back(to_string(arr[cnt+1]));
                backtrack(cnt+1);
                v.pop_back(); v.pop_back();
                op[i]++;
            }
        }
    }
    return 0;
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int temp;
        scanf("%d", &temp);
        arr[i]=temp;
    }
    for(int i=0; i<4; i++){
        cin>>op[i];
    }

    v.push_back(to_string(arr[0]));
    backtrack(0);
    cout<<mx<<endl<<mn<<endl;
    
    return 0;
}