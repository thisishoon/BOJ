#include <iostream>

using namespace std;

void selectionSort(int *arr, int len){  //가장 작은 값은 선택
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

void insertionSort(int *arr, int len){  //key값이 들어갈 자리를 찾기까지 한 칸씩 밈
    for(int i=1; i<len; i++){
        int key = arr[i];
        int j;
        // for(j=i-1; j>=0 && arr[j]>key; j--){  
        //     arr[j+1] = arr[j];
        // }
        // arr[j+1] = key;
        for(j=i-1; j>=0; j--){
            if(arr[j]>key) arr[j+1] = arr[j];
            else break;
        }
        arr[j+1] = key;
    }
}

int sorted[10];

void merge(int *arr, int left, int right){
    int mid = (left+right)/2;
    int i = left;
    int j = mid+1;
    int k = left;

    while(i<=mid && j<=right){
        if(arr[i] <= arr[j]){
            sorted[k++] = arr[i++];
        }
        else{
            sorted[k++] = arr[j++];
        }
    }

    if(i>mid){
        for(int t=j; t<=right; t++){
            sorted[k++] = arr[t];
        }
    }
    else{
        for(int t=i; t<=mid; t++){
            sorted[k++] = arr[t];
        }
    }

    for(int t=left; t<=right; t++){
        arr[t] = sorted[t];
    }
}

void mergeSort(int *arr, int left, int right){  //분할 후 병합 과정에서 정렬
    if(left<right){
        int mid = (left+right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, right);
    }
}


void quickSort(int *arr, int start, int end){   //pivot을 기준으로 정렬한 뒤 분할
    // if(start >= end){
    //     return;
    // }
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

void bubbleSort(int* arr, int len){
    for(int i=0; i<len; i++){
        for(int j=0; j<len-1-i; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void permutaion(int arr[], int start, int end){
    if(start==end){
        for(int i=0; i<5; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    else{
        for(int i=start; i<=end; i++){
            swap(arr[start], arr[i]);
            permutaion(arr, start+1, end);
            swap(arr[start], arr[i]);
        }
    }
}

int check[5];

void combination(int arr[], int idx, int num, int cnt){
    if(num==cnt){
        for(int i=0; i<5; i++){
            if(check[i]==1) cout<<arr[i]<<" ";
        }
        cout<<endl;
        return;
    }
    else{
        for(int i=idx; i<5; i++){
            check[i] = 1;
            combination(arr, i+1, num, cnt+1);
            check[i] = 0;
        }
    }
}

void heapify(int arr[], int index, int size){
    int largest = index;
    int left_index = index*2;
    int right_index = index*2+1;
    if(left_index<=size && arr[largest]<arr[left_index])
        largest = left_index;
    if(right_index<=size && arr[largest]<arr[right_index])
        largest = right_index;
    if(largest != index){
        swap(arr[largest], arr[index]);
    }
    heapify(arr, largest, size);
}

void heapSort(int arr[], int size){
    //build heap;
    for(int i=size/2; size>=1; i--) heapify(arr, i, size);
    
    for(int s=size; s>0; s--){
        swap(arr[0], arr[s]);
        heapify(arr, 0, s);
    }
}


int main(){
    int arr[11] = {0, 1100,123,36,1,78,44,2,43,99,11111};
    // quickSort(arr, 0, 9);
    insertionSort(arr, 10);
    // mergeSort(arr, 0, 9);
    // bubbleSort(arr, 10);
    heapSort(arr, 10);

    for(int i=0; i<10; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    // int arr2[5] = {1,2,3,4,5};
    // combination(arr2, 0, 3, 0);
    
}