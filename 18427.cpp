#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n, m, h;
vector<int> v[55];
long long arr[55][1011];

int main(){
    cin>>n>>m>>h;
    cin.ignore(1);
    for(int i=1; i<=n; i++){
        string str;
        getline(cin, str);
        int num=0;
        for(int j=0; j<=str.length(); j++){
            if(j==str.length()){
                v[i].push_back(num);
            }
            else if(str[j]==' '){
                v[i].push_back(num);
                num=0;
            }
            else{
                num = num*10;
                num += str[j]-'0';
            }
        }
    }

    
    

    for(int i=1; i<=n; i++){
        for(int j=1; j<=h; j++){
            arr[i][j] = arr[i-1][j];
            for(int k=0; k<v[i].size(); k++){
                int num = v[i][k];
                if(num==j) arr[i][j] = ((arr[i][j]+1)%10007);
                if(j-num > 0){
                    if(arr[i-1][j-num]>0) arr[i][j] += ((arr[i-1][j-num])%10007);
                }
            }
        }
    }

    cout<<arr[n][h]%10007<<endl;
    
    return 0;
}