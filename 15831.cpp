#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;
int n, b, w;
char arr[300003];
int answer=0;
int black, white;
deque<char> de;

int main(){
    scanf("%d %d %d\n", &n, &b, &w);
    for(int i=0; i<n; i++){
        scanf("%c", &arr[i]);
    }
    for(int i=0; i<n; i++){
        de.push_back(arr[i]);
        if(arr[i]=='B') black++;
        else white++;

        while(black>b){
            if(de.front()=='B') black--;
            else if(de.front()=='W') white--;
            de.pop_front();
        }
        if(white>=w) answer = max(answer, (int)de.size());
        // for(int i=0; i<de.size(); i++){
        //     cout<<de[i]<<" ";
        // }
        // cout<<de.size()<<endl;
        // cout<<endl;
    }
    printf("%d\n", answer);
    return 0;
}