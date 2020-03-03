#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int arr[50][50];
int result=0;
int n;
int test=0;

void top(){
    for(int j=1; j<=n; j++){
        queue<int> q;
        for(int i=1; i<=n; i++){
            if(arr[i][j]) {
                q.push(arr[i][j]);
                arr[i][j]=0;
            }
        }
        int index = 1;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            if(arr[index][j]==0) arr[index][j]=temp;
            else{
                if(arr[index][j]==temp){
                    arr[index][j]*=2;
                    index++;
                }
                else{
                    arr[++index][j]=temp;
                }
            }
        }
    }
}
void down(){
    for(int j=1; j<=n; j++){
        queue<int> q;
        for(int i=n; i>0; i--){
            if(arr[i][j]) {
                q.push(arr[i][j]);
                arr[i][j]=0;
            }
        }
        int index = n;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            if(arr[index][j]==0) arr[index][j]=temp;
            else{
                if(arr[index][j]==temp){
                    arr[index][j]*=2;
                    index--;
                }
                else{
                    arr[--index][j]=temp;
                }
            }
        }
    }
}
void right(){
    for(int i=1; i<=n; i++){
        queue<int> q;
        for(int j=n; j>0; j--){
            if(arr[i][j]) {
                q.push(arr[i][j]);
                arr[i][j]=0;
            }
        }
        int index = n;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            if(arr[i][index]==0) arr[i][index]=temp;
            else{
                if(arr[i][index]==temp){
                    arr[i][index]*=2;
                    index--;
                }
                else{
                    arr[i][--index]=temp;
                }
            }
        }
    }
}
void left(){
    for(int i=1; i<=n; i++){
        queue<int> q;
        for(int j=1; j<=n; j++){
            if(arr[i][j]) {
                q.push(arr[i][j]);
                arr[i][j]=0;
            }
        }
        int index = 1;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            if(arr[i][index]==0) arr[i][index]=temp;
            else{
                if(arr[i][index]==temp){
                    arr[i][index]*=2;
                    index++;
                }
                else{
                    arr[i][++index]=temp;
                }
            }
        }
    }
}

void check_max(){
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) result=max(result, arr[i][j]);
}

void simulation(int cnt){
    if(cnt==5) return;
    int temp[52][52];
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) temp[i][j]=arr[i][j];
    for(int d=0; d<4; d++){ //4direction
        if(d==0){
            top();
            check_max();
            simulation(cnt+1);
            for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) arr[i][j]=temp[i][j];
        }
        else if(d==1){
            down();
            check_max();
            simulation(cnt+1);
            for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) arr[i][j]=temp[i][j];
        } 
        else if(d==2){
            left();
            check_max();
            simulation(cnt+1);
            for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) arr[i][j]=temp[i][j];
        }
        else{
            right();
            check_max();
            simulation(cnt+1);
            for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) arr[i][j]=temp[i][j];
        }
    }
    return;
}

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) scanf("%d", &arr[i][j]);
    if(n==1){
        cout<<arr[1][1]<<endl;
        return 0;
    }
    simulation(0);
    printf("%d\n", result);
    return 0;
}