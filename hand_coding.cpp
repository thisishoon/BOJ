#include <iostream>
#include <random>
#include <ctime>
#include <cstring>
#include <algorithm>

using namespace std;

int fibo(int order){
    if(order<=1) return 1;
    return fibo(order-1) + fibo(order-2);
}

int arr[100];
int memoization_fibo(int order){
    if(order<=1){
        arr[order] = 1;
        return 1;
    }
    if(arr[order]>0) return arr[order];
    arr[order] = memoization_fibo(order-1) + memoization_fibo(order-2);
    return arr[order];
}

int factorial(int num){
    if(num <= 1) return 1;
    return num*factorial(num-1);
}

int binary_search(int arr[], int len, int number){
    int left = 0;
    int right = len-1;

    while(left<=right){
        int mid = (left+right)/2;
        if(arr[mid]==number){
            return mid;
        }
        else if(arr[mid]>number){
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }

    return -1;
}

void genRandom(){
    srand((unsigned int)time(0));
    int iterations = 10;
    for(int i=0; i<iterations; i++){
        int r = rand()%10 +1;
        cout<<r<<" ";
    }
    cout<<endl;
    return;
}

bool is_duplicated_char(string a, string b){
    //O(n^2)
    // for(int i=0; i<a.size(); i++){
    //     for(int j=0; j<b.size(); j++){
    //         if(a[i]==b[j]) return true;
    //     }
    // }
    // return false;

    int check[126];
    memset(check, 0, sizeof(check));
    for(int i=0; i<a.size(); i++){
        check[a[i]]++;
    }
    
    for(int j=0; j<b.size(); j++){
        if(check[b[j]]>0) return true;
    }
    return false;
}

int* buble_sort(int arr[], int len){
    for(int i=0; i<len; i++){
        for(int j=0; j<len-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j]=temp;
            }
        }
    }
    return arr;
}

int strcmp(string a, string b){
    int len1 = a.length();
    int len2 = a.length();

    int minLen;
    int minIdx;
    if(len1 < len2) minLen = len1;
    else minLen = len2;

    for(int i=0; i<minLen; i++){
        if(a[i] == b[i]) continue;
        else if(a[i]<b[i]) return -1;
        else return 1;
    }
    if(len1 == len2) return 0;
    else if(len1 < len2) return -1;
    else return 1;
}

string strrev(string a){
    int len = a.length();
    for(int i=0; i<len/2; i++){
        char temp = a[i];
        a[i] = a[len-1-i];
        a[len-i-1]=temp;
    }
    return a;
}

int count_longest_length(string a){
    int cnt=1;
    int max=1;
    int pre=0;
    if(a.size()==0) return 0;
    for(int i=1; i<a.size(); i++){
        if(a[i] == a[pre]){
            cnt++;
            if(max<cnt) max=cnt;
        }
        else{
            cnt=1;
            pre=i;
        }
    }
    return max;
}



int main(){
    cout<<"10번 째 피보나치 수 "<<fibo(10)<<endl;
    cout<<"10번 째 피보나치 수 "<<memoization_fibo(10)<<endl;
    cout<<"10! "<<factorial(5)<<endl;
    genRandom();
    int arr[]={1,2,3,4,5};
    cout<<"binary serarch "<<binary_search(arr, 5, 3)<<endl;
    cout<<"두 문자열 중 중복되는 문자가 있는지 확인 "<<is_duplicated_char("강강", "a");
    cout<<(long long)"각"<<endl;
    int arr2[]={1,3,2,8,4,5,7};
    int * arr3 = buble_sort(arr2, 7);
    for(int i=0; i<7; i++){
        cout<<arr3[i]<<" ";
    }cout<<endl;
    cout<<"문자열 비교 "<<strcmp("azcde", "abcd");
    cout<<"문자열 뒤집기 "<<strrev("hello world");
    cout<<"문자열에서 연속적으로 반복되는 가장 긴 길이 "<<count_longest_length("aaabbbe")<<endl;

    
}