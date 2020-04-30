#include <iostream>
#include <cstring>
using namespace std;

int main(){
    string str; cin>>str;
    int answer=0;
    for(int i=0; i<str.length(); i++){
        char c = str[i];
        char nc = str[i+1];
        if(c=='c'){
            if(nc=='=' || nc=='-'){
                answer++; i++;
                continue;
            }
        }
        else if(c=='d'){
            if(nc=='z' && str[i+2]=='='){
                answer++; i+=2;
                continue;
            }
            else if(nc=='-'){
                answer++; i++;
                continue;
            }
        }
        else if( (c=='l'||c=='n') && nc=='j'){
            answer++; i++;
            continue;
        }
        else if( (c=='s'||c=='z') && nc=='='){
            answer++; i++;
            continue;
        }
        answer++;
    }
    cout<<answer<<endl;
    

    return 0;
}