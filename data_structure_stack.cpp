#include <iostream>

using namespace std;

int* Stack;
int Size;
int Top;

void initStack(int size){
    Size = size;
    Stack = (int*)malloc(size*sizeof(int));
    Top = -1;
}

void push(int data){
    if(Top < Size-1){
        Stack[++Top] = data;
    }
    else{
        cout<<"stack is full"<<endl;
    }
}

void pop(){
    if(Top>=0){
        cout<< Stack[Top--] <<endl;
    }
    else{
        cout<<"stack is empty"<<endl;
    }
}

void freeStack(){
    free(Stack);
}

int main(){
    initStack(3);
    pop();
    push(1);
    push(2);
    push(3);
    push(4);
    pop(); pop(); pop(); pop();
}