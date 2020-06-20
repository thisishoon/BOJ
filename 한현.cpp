#include <iostream>
#include <algorithm>
using namespace std;

int answer=0;
int n=5;
int m=3;

int arr[111];

int solution(int dots[], int lines[]){
    int n = sizeof(dots);
    int first = dots[0];
    int last = dots[n-1];
    for(int i=0; i<n; i++){
        arr[dots[i]]=1;
    }
    sort(lines, lines+m, greater<int>());

    for(int num=0; num<m; num++){   //선분을 고르고
        int line = lines[num];
         int mx=0;
         int mp=0;

        for(int i=0; i<=last-line; i++){
            int temp=0;
            for(int j=i; j<=i+line; j++){
                if(arr[j]) temp++;
            }
            if(mx<temp){
                mx=temp;
                mp=i;
            }
        }
        for(int i=mp; i<=mp+line; i++){ //가장 많이 포함하는 곳 지우기

            arr[i]=0;
        }
        int flag=0; //전부 덮었는지 확인
        for(int i=0; i<=100; i++){
            if(arr[i]){
                flag=1; break;
            }
        }
        if(flag==0) return num+1;
    }
    return -1;
}

int main(){
    int dots[5]={1,50,51,52,100};
    int lines[3]={1,1,5};
    int answer = solution(dots, lines);
    cout<<"정답은"<<answer<<endl;

}




// 1           50 51 52 53 54 55            100
// 1 5  1 가능