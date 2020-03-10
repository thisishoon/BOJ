#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int n, l;
int arr[101][101];
int result;

int main(){
    cin>>n>>l;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin>>arr[i][j];

    for(int i=1; i<=n; i++){
        int flag = 0;
        int visited[101];
        memset(visited, 0, sizeof(visited));
        for(int j=1; j<n; j++){
            if(arr[i][j]!=arr[i][j+1]){
                if(abs(arr[i][j]-arr[i][j+1])!=1){
                    flag=1; break;
                }
                else{   //1칸 차이
                    if(arr[i][j]-arr[i][j+1]<0){    //상승
                        for(int k=1; k<=l; k++){
                            if((j+1-k)==0 ){
                                flag=1; break;
                            }
                            if(arr[i][j+1-k]!=arr[i][j]){
                                flag=1; break;
                            }
                            if(visited[j+1-k]==1){
                                flag=1; break;
                            }
                        }
                    }
                    else{//하강
                        for(int k=1; k<=l; k++){
                            if((j+k)>n ){
                                flag=1; break;
                            }
                            if(arr[i][j+1]!=arr[i][j+k]){
                                flag=1; break;
                            }
                            if(visited[j+k]==1){
                                flag=1; break;
                            }
                        }
                    }




                    if(flag==0){
                        if(arr[i][j]-arr[i][j+1]<0){//상승
                            for(int k=1; k<=l; k++) visited[j+1-k]=1;
                        }
                        else{//하강
                            for(int k=1; k<=l; k++) visited[j+k]=1;
                        }
                    }
                }
            }
        }

        if(flag==0){
            result++;
        }
    }

    for(int j=1; j<=n; j++){
        int flag=0;
        int visited[101];
        memset(visited, 0, sizeof(visited));
        for(int i=1; i<n; i++){
            if(arr[i][j]!=arr[i+1][j]){
                if(abs(arr[i][j]-arr[i+1][j])!=1){
                    flag=1; break;
                }

                else{   //1칸 차이
                    if(arr[i][j]-arr[i+1][j]<0){//상승
                        for(int k=1; k<=l; k++){
                            if((i+1-k)==0 ){
                                flag=1; break;
                            }
                            if(arr[i+1-k][j]!=arr[i][j]){
                                flag=1; break;
                            }
                            if(visited[i+1-k]==1){
                                flag=1; break;
                            }
                        }
                    }
                    else{//하강
                        for(int k=1; k<=l; k++){
                            if((i+k)>n ){
                                flag=1; break;
                            }
                            if(arr[i+1][j]!=arr[i+k][j]){
                                flag=1; break;
                            }
                            if(visited[i+k]==1){
                                flag=1; break;
                            }
                        }
                    }

                    if(flag==0){
                        if(arr[i][j]-arr[i+1][j]<0){//상승
                            for(int k=1; k<=l; k++) visited[i+1-k]=1;
                        }
                        else{//하강
                            for(int k=1; k<=l; k++) visited[i+k]=1;
                        }
                    }
                }
            }
        }
        if(flag==0){
            result++;
        }
    }


    cout<<result<<endl;
    
    return 0;
}
