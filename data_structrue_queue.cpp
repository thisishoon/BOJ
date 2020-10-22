#include <iostream>

using namespace std;

int *Queue;
int Size;
int head, tail;
int num;

void initQueue(int size){
    Queue = (int*)malloc(size*sizeof(int));
    Size = size;
    head = 0;
    tail = 0;
    num = 0;
}

void push(int data){
    if(num==Size){
        cout<<"Queue is full"<<endl;
    }
    else{
        cout<<data<<"push"<<endl;
        num++;
        Queue[tail] = data;
        tail = (tail+1) % Size;
    }
}

void pop(){
    if(num==0){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<Queue[head]<<"pop"<<endl;
        num--;
        head = (head+1)%Size;
    }
}

void freeQueue(){
    free(Queue);
}

int main(){
    initQueue(3);
    pop();
    push(1); push(2); push(3); push(4);
    pop(); pop(); pop(); pop();
    push(1); push(1); push(1); push(1); push(1); 
    freeQueue();
    return 0;
}