#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
int n, m, d;
int arr[20][20];
int archer[4];
vector<pair<int, int> > temp;
int answer;

void offense(){
    vector<pair<int, int> > v;
    v.assign(temp.begin(), temp.end());
    int die=0;
    while(1){
        if(v.size()==0){
            answer = max(answer, die);
            return;
        }
        set<int> died;
        for(int i=1; i<=3; i++){    //각 궁수에 대하여
            int tempX=0;
            int tempD=999999999;
            int tempI=-1;
            for(int j=0; j<v.size(); j++){  //각 적에 대하여
                int distance = abs(archer[i]-v[j].second)+(n+1-v[j].first);

                if(distance<=d){
                    if(distance<tempD){
                        tempX = v[j].second;
                        tempD = distance;
                        tempI = j;
                    }
                    else if(distance==tempD){
                        if(v[j].second<tempX){
                            tempX = v[j].second;
                            tempD = distance;
                            tempI=j;
                        }
                    }
                }
            }
            if(tempI!=-1){
                died.insert(tempI);
            }
        }
        for(auto it=died.rbegin(); it!=died.rend(); it++){
            int temp = *it;
            v.erase(v.begin() + temp);
            die++;
        }

        for(int i=0; i<v.size(); i++){  //적 이동
            v[i].first++;
            if(v[i].first==n+1){
                v.erase(v.begin()+i);
                i--;
            }
        }
    }
}
    
    




void combination(int num, int last){
    if(num==4){
        offense();
        return;
    }
    for(int i=last; i<=m; i++){
        archer[num]=i;
        combination(num+1, i+1);
    }
}

int main(){
    cin>>n>>m>>d;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>arr[i][j];
            if(arr[i][j]==1){
                temp.push_back(make_pair(i, j));
            }
        }
    }
    combination(1, 1);
    
    cout<<answer<<endl;

    return 0;
}