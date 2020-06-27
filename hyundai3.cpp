#include <vector>
#include <string>
#include <iostream>
#include <set>

using namespace std;

bool search2(vector<string> registered_list, string new_id) {
   for (int i = 0; i < registered_list.size(); i++) {
      if (registered_list[i] == new_id) return false;
   }

   return true;
}

bool search(set<string> s, string new_id){
    if(s.find(new_id)==s.end()) return true;
    else return false;
}



vector<string> splitId(string new_id) {
   vector<string> result;
   
   int ind = 0;
   for (int i = 0; i < new_id.size(); i++) {
      if ('0' <= new_id[i] && new_id[i] <= '9') {
         ind = i;
         break;
      }
   }
   if (ind == 0) {
      result.push_back(new_id);
      result.push_back("");
   }
   else {
      result.push_back(new_id.substr(0, ind));
      result.push_back(new_id.substr(ind, new_id.size() - ind));
   }

   return result;
}

string solution(vector<string> registered_list, string new_id) {
    set<string> s;
    for(int i=0; i<registered_list.size(); i++){
        s.insert(registered_list[i]);
    }

   //if (search(registered_list, new_id)) return new_id;
   if (search(s, new_id)) return new_id;


   while (!search(s, new_id)) {
      vector<string> split_id = splitId(new_id);
      new_id = split_id[0];
      if (split_id[1] == "") {
         new_id += '1';
      }
      else {
         new_id += to_string(stoi(split_id[1]) + 1);
      }
   }
   

   return new_id;
}

int main(){
    vector<string> v;
    v.push_back("card");
    v.push_back("ace13");
    v.push_back("ace16");
    v.push_back("banker");
    v.push_back("ace17");
    v.push_back("ace14");
    cout<<solution(v, "ace15")<<endl;
    return 0;
}