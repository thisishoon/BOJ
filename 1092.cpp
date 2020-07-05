#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m;
int crane[51];
vector<int> box;
int answer;
int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>crane[i];
    }
    cin>>m;
    for(int i=0; i<m; i++){
        int temp; cin>>temp;
        box.push_back(temp);
    }
    sort(crane, crane+n, greater<int>());
    sort(box.begin(), box.end(), greater<int>());

    while(box.size()){
        answer++;
        int temp=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<box.size(); j++){
                if(crane[i] >= box[j]){
                    temp=1;
                    box.erase(box.begin()+j);
                    break;
                }
            }
        }
        if(temp==0){
            answer=-1;
            break;
        }
    }
    cout<<answer<<endl;
    


    return 0;
}