#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[50][10];
int per[8]; //순서
int score;

void offense(){
    int answer=0;
    int start=0;    //첫 스타트는 1번 선수부터 타격
    for(int k=0; k<n; k++){ //이닝을 반복
        int ru[4];
        ru[0]=ru[1]=ru[2]=ru[3]=0;
        int outCnt=0;
        while(1){
            int flag=0;
            for(int i=start; i<9; i++){
                int power;
                if(i==3)    power = arr[k][0]; //4번 타자는 첫번 째 선수
                else if(i>3)    power = arr[k][per[i-1]];
                else    power = arr[k][per[i]];

                if(power==0)    outCnt++;
                else if(power==4){
                    for(int i=0; i<3; i++){
                        if(ru[i]==1) answer++;
                        ru[i]=0;
                    }
                    answer++;
                }
                else if(power==1){
                    answer+=ru[2];
                    ru[2]=ru[1];
                    ru[1]=ru[0];
                    ru[0]=1;
                }
                else if(power==2){
                    answer+= (ru[2]+ru[1]);
                    ru[2]=ru[0];
                    ru[1]=1;
                    ru[0]=0;
                }
                else if(power==3){
                    answer += (ru[2]+ru[1]+ru[0]);
                    ru[2]=1; ru[1]=ru[0]=0;
                }

                if(outCnt==3){
                    start = (i+1)%9;
                    flag=1; 
                    break;
                }
            }
            if(flag){
                break;
            }
            start=0;
        }
    }
    score = max(score, answer);
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<9; j++){
        scanf("%d", &arr[i][j]);
        }
    }
    for(int i=0; i<8; i++){
        per[i]=i+1;
    }
    offense();
    while(next_permutation(per, per+8)){
        offense();
    }
    cout<<score<<endl;
    return 0;
}