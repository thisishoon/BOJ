#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* left;
    Node* right;
};
Node* root;

void preorder(Node* n){
    if(n!=NULL){
        cout<<n->value<<" ";
        preorder(n->left);
        preorder(n->right);
    }

}

void inorder(Node* n){
    if(n!=NULL){
        inorder(n->left);
        cout<<n->value<<" ";
        inorder(n->right);
    }
}

void postorder(Node* n){
    if(n!=NULL){
        inorder(n->left);
        inorder(n->right);
        cout<<n->value<<" ";
    }
}

int main(){
    preorder(root);

    return 0;
}