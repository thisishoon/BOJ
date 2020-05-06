#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n,m,t;
int x, d, k;
int arr[55][55];
int temp[55];

void rotate(){
    for(int i=x; i<=n; i+=x){
        if(d==0){   //시계
            // int temp[55];
            for(int j=1; j<=m; j++){
                temp[((j-1+k)%m)+1] = arr[i][j];
            }
            for(int j=1; j<=m; j++){
                arr[i][j]=temp[j];
            }
        }
        else{   //반시계
            // int temp[55];
            for(int j=1; j<=m; j++){
                temp[((j-1+m-k)%m)+1] = arr[i][j];
            }
            for(int j=1; j<=m; j++){
                arr[i][j]=temp[j];
            }
        }
    }
}
void check(){
    int flag=0;
    int temp[55][55];
    memcpy(temp, arr, sizeof(arr));
    double sum=0;
    int cnt=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(arr[i][j]!=0){
                sum+=arr[i][j];
                cnt++;
            }
        }
    }
    double avg = 0;
    if(cnt>0) avg = sum / cnt;
    else return;
    

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int next = (j+1);
            if(next>m) next=1;
            if(arr[i][j]==arr[i][next]){
                if(arr[i][j]!=0){
                    temp[i][j]=temp[i][next]=0;
                    flag=1;
                }
            }
        }
    }
    
    for(int j=1; j<=m; j++){
        for(int i=1; i<n; i++){
            if(arr[i][j]==arr[(i+1)][j]){
                if(arr[i][j]!=0){
                    temp[i][j]=temp[(i+1)][j]=0;
                    flag=1;
                }
            }
        }
    }
    

    if(flag==0){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(temp[i][j]>0){
                    if(avg<temp[i][j]) temp[i][j]--;
                    else if(avg>temp[i][j]) temp[i][j]++;
                }
            }
        }
    }
    memcpy(arr, temp, sizeof(arr));
}

void prin(){
    cout<<"------------"<<endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

}

int main(){
    cin>>n>>m>>t;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>arr[i][j];
        }
    }
    while(t--){
        cin>>x>>d>>k;
        rotate();
        //prin();
        check();
        //prin();
    }
    int answer=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(arr[i][j]!=0) answer+=arr[i][j];
        }
    }
    cout<<answer<<endl;

    return 0;
}