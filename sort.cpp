#include <iostream>

using namespace std;

void selectionSort(int *arr, int len){
    for(int i=0; i<len-1; i++){
        int minIdx=i;
        for(int j=i+1; j<len; j++){
            if(arr[minIdx] > arr[j]){
                minIdx = j;
            }
        }
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

void insertionSort(int *arr, int len){
    for(int i=1; i<len; i++){
        int key = arr[i];
        int j;
        for(j=i-1; j>=0 && arr[j]>key; j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = key;
    }
}

void quickSort(int *arr, int start, int end){
    if(start >= end){
        return;
    }
    int pivot = start;
    int i = pivot + 1;
    int j = end;
    int temp;
    while(i<=j){
        while(i<=end && arr[i] <= arr[pivot]){
            i++;
        }
        while(j>start && arr[j] >= arr[pivot]){
            j--;
        }
        if(i>j){
            temp = arr[j];
            arr[j] = arr[pivot];
            arr[pivot] = temp;
        }
        else{
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    quickSort(arr, start, j-1);
    quickSort(arr, j+1, end);
}

int main(){
    int arr[10] = {1100,123,36,1,78,44,2,43,99,11111};
    // quickSort(arr, 10);
    insertionSort(arr, 10);
    for(int i=0; i<10; i++){
        cout<<arr[i]<<" ";
    }
    
}