#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int len, wid, hei;
int n;
vector<pair<int, int> > v;
int answer;
int flag=1;

void divide(int y, int x, int d){
    if(!flag)   return;

    if(y==0 || x==0 || d==0) return;

    for(int i=0; i<v.size(); i++){
        if(v[i].second==0) continue;

        int size = v[i].first;

        if(size <= y && size <=x && size <=d){
            v[i].second--;
            answer++;

            divide(y, x, d-size);
            divide(y, x-size, size);
            divide(y-size, size, size);
            return;
        }
    }
    flag=0;
    return;
}


int main(){
    cin>>len>>wid>>hei;
    cin>>n;
    for(int i=0; i<n; i++){
        int a, b;   cin>>a>>b;
        v.push_back({pow(2,a),b});
    }
    sort(v.begin(), v.end(), greater<pair<int, int> >());

    divide(len, wid, hei);
    if(!flag) cout<<-1<<endl;
    else cout<<answer<<endl;


    return 0;
}