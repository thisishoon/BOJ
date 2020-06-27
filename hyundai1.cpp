#include <vector>
#include <string>
#include <iostream>

using namespace std;

int month[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int day[365];
int bronze;
int silver;
int gold;
int plat;
int dia;


vector<string> splitByChar(string str, char ch) {
   vector<string> result;
   int ind = 0;
   
   for (int i = 0; i < str.size(); i++) {
      if (str[i] == ch) {
         result.push_back(str.substr(ind, i - ind ));
         ind = i+1;
      }

   }
   result.push_back(str.substr(ind, str.size() - ind));

   return result;
}

int findLastDay(int num) {
   return month[num];
}
int switchDay(int m, int d) {
   int result = 0;
   for (int i = 1; i < m; i++) {
      result += month[i];
   }
   result += d;

   return result;
}

vector<int> solution(vector<string> purchase) {
   vector<int> result(5, 0);
   for (int i = 0; i < purchase.size(); i++) {
      vector<string> splitPurchase = splitByChar(purchase[i], ' ');
      vector<string> splitDay = splitByChar(splitPurchase[0], '/');
      //day[stoi(splitDay[0])][stoi(splitDay[1])] = stoi(splitPurchase[1]);
      day[switchDay(stoi(splitDay[1]), stoi(splitDay[2]))] = stoi(splitPurchase[1]);
   }
   
   
   for (int i = 1; i <= 365; i++) {
      int sum = 0;
      for (int j = i; j > i - 30; j--) {
         if (j == 0) break;
         sum += day[j];
      }
      if (100000 <= sum) {
         result[4]++;
      }
      else if (50000 <= sum && sum < 100000) {
         result[3]++;
      }
      else if (20000 <= sum && sum < 50000) {
         result[2]++;
      }
      else if (10000 <= sum && sum < 20000) {
         result[1]++;
      }
      else {
         result[0]++;
      }
   }

   return result;
}

int main(){
    vector<string> v;
    v.push_back("2019/01/01 5000");
    v.push_back("2019/01/20 15000");
    v.push_back("2019/02/09 90000");
    vector<int> answer = solution(v);
    for(int i=0; i<answer.size(); i++){
        cout<<answer[i]<<" ";
    }
}