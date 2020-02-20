#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
vector<string> v;
vector<vector<string> > order[200002];
int main(){
    string a = "alex pizza pasta";
    string b = "alex pizza pizza";
    string c = "alex noodle";
    string d = "bob pasta";
    string e = "bob noodle sandwitch pasta";
    string f = "bob steak noodle";
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);
    v.push_back(e);
    v.push_back(f);
    for(int i=0; i<v.size(); i++){
        int pos=0;
        for(int j=0; j<v[i].size(); j++){
            if(v[i][j]==' '){
                for(int k=pos; k<j; k++){
                    if(pos==0){    //이름
                        string name = v[i].substr(pos, pos+j);
                        order.push_back(name);
                    }
                    else{   //음식
                        
                    }
                }
                pos=j+1;
                cout<<endl;
            }
        }
    }
    


    

}