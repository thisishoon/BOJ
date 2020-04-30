#include <iostream>
using namespace std;

int main(){
    char buf[1000002];   
    cin.getline(buf, sizeof(buf));
    int answer=0;
    char *tok = strtok(buf, " ");
    while(tok!=NULL){
        answer++;
        tok = strtok(NULL, " ");
    }
    cout<<answer<<endl;
    return 0;
}