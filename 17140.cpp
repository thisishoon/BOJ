#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int arr[111][111];
int answer;

int r,c,k;
int R = 3;
int C = 3;

int comp(pair<int, int>a, pair<int, int>b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    else if(b.second==0) return 1;
    else if(a.second==0) return 0;
    else return a.second<b.second;
}

void func(){
    if(R>=C){
        int temp=0;
        for(int i=1; i<=R; i++){
            pair<int, int> cnt[111];
            for(int j=1; j<=C; j++){
                cnt[arr[i][j]].first=arr[i][j];
                cnt[arr[i][j]].second++;
            }
            sort(cnt+1, cnt+1+100, comp);
            

            for(int j=1; j<=C; j++){
                if(cnt[j].second==0){
                    for(int k=j; k<=C; k++){
                        arr[i][k*2-1] = 0;
                        arr[i][k*2] = 0;
                    }
                    break;
                }
                if(j>50) break;
                arr[i][j*2-1] = cnt[j].first;
                arr[i][j*2] = cnt[j].second;
                temp = max(temp, j*2);
            }
        }
        C = temp;
    }
    else{
        int temp = 0;
        for(int j=1; j<=C; j++){
            pair<int, int> cnt[111];
            for(int i=1; i<=R; i++){
                cnt[arr[i][j]].first=arr[i][j];
                cnt[arr[i][j]].second++;
            }
            sort(cnt+1, cnt+1+100, comp);
            for(int i=1; i<=R; i++){
                if(cnt[i].second==0){
                    for(int k=i; k<=R; k++){
                        arr[k*2-1][j]=0;
                        arr[k*2][j]=0;
                    }
                    break;
                }
                if(i>50) break;
                arr[i*2-1][j] = cnt[i].first;
                arr[i*2][j] = cnt[i].second;
                temp = max(temp, 2*i);
            }
        }
        R = temp;
    }    
}

void prin(){
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"------------"<<endl;
}

int main(){
    cin>>r>>c>>k;
    for(int i=1; i<=3; i++){
        for(int j=1; j<=3; j++){
            cin>>arr[i][j];
        }
    }

   
    if(arr[r][c]==k){
        cout<<"0"<<endl;
        return 0;
    }
    while(1){
        func();
        //prin();
        // cout<<R<<" "<<C<<endl;
        answer++;
        if(answer>100){
            cout<<"-1"<<endl;
            return 0;
        }
        if(arr[r][c]==k){
            cout<<answer<<endl;
            return 0;
        }
    }

    return 0;
}