#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int arr[22][22];
int result=999999999;
int visited[22];

int backtrack(int cnt, int pos){
    if(cnt == n/2){ //나눠졌다면 계산
        int sum_start=0;
        int sum_link=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(i==n) continue;
                if(visited[i] && visited[j]){
                    sum_start += arr[i][j];
                    sum_start += arr[j][i];
                }
                else if(!visited[i] && !visited[j]){
                    sum_link += arr[i][j];
                    sum_link += arr[j][i];
                }
            }
        }
        int d = abs(sum_start-sum_link);
        if(result>d) result = d;
        return 0;
    }

    for(int i=pos; i<n; i++){ //n명까지 뽑을까 말까
        if(!visited[i]){
            visited[i]=1;
            backtrack(cnt+1, i+1);
            visited[i]=0;
        }
    }
    return 0;
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    backtrack(0, 0);
    printf("%d", result);

    return 0;
}