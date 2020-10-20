#include <iostream>

using namespace std;

struct Node{
    Node *next;
    int data;
};

Node* head = NULL;

void print(){
    Node* cur = head;
    while(cur!=NULL){
        cout<<cur->data<<" ";
        cur = cur -> next;
    }
    cout<<endl;
}

void insertToLinkedList(int data, int position){
    Node* inserted = new Node;
    inserted -> data = data;

    if(position == 1 || head == NULL){
        inserted -> next = head;
        head = inserted;
    }
    else{
        Node* prev = head;
        for(int i=1; i<position; i++){
            if(prev->next==NULL) break;
            prev = prev -> next;
        }
        inserted -> next = prev -> next;
        prev -> next = inserted;
    }
}

bool isEmpty(){
    if(head==NULL) return true;
    else return false;
}

void deleteFromLinkedList(int position){
    if(isEmpty()){
        cout<<"linked list is empty"<<endl;
    }
    Node* removed;
    Node* removed_prev;
    if(position==1){
        head = head -> next;
    }
    else{
        removed_prev = head;
        removed = removed_prev -> next;

        for(int i=2; i<position; i++){
            if(removed->next==NULL) break;
            removed_prev = removed;
            removed = removed -> next;
        }
        if(removed_prev==head && head->next == NULL){
            head = NULL;
            return;
        }
        removed_prev -> next = removed -> next;
    }
    return;
}


int main(){
    insertToLinkedList(1, 1); 
    insertToLinkedList(2, 2);
    // insertToLinkedList(3, 3);
    print();
    deleteFromLinkedList(1);
    // deleteFromLinkedList(2);
    // deleteFromLinkedList(10);
    print();

    return 0;
}