#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *left , *right ;
    Node (int data){
        this->data = data;
        left = right = NULL ;
    }
};

// Inorder -> left, root, right;
void inorder (struct Node *node) {
    if (node == NULL) {
        return ;
    }
    inorder(node->left);
    cout << node->data << "->" ;
    inorder (node->right);
}

// Preorder -> root, left, right;
void preorder (struct Node *node) {
   if (node == NULL){
       return;
   }
   cout << node->data << "->" ;
   preorder(node->left);
   preorder(node->right);
};

// Postorder ->left, right, root;
void postorder (struct Node *node) {
    if (node == NULL) {
        return;
    }
    postorder(node->left);
    postorder(node->right);
    cout << node->data << "->" ;
}


int main () {
    struct Node *root = new Node (8);
    root->left = new Node (10);
    root->right = new Node (3);

    root->right->left = new Node (17);
    root->left->left = new Node (4);
    root->left->right = new Node (2);
    //test 
    root->left->left->left = new Node (6);
    root->left->left->right = new Node (5);
    root->left->right->left = new Node (1);
    root->left->right->right = new Node (9);
    root->right->right = new Node (7);
    root->right->right->right = new Node (11);

    cout << " Inorder Traversal : " ;
    inorder(root);

    cout << "\n Preorder Traversal : " ;
    preorder(root);

    cout << "\n Postorder Traversal : " ;
    postorder(root);

    return 0;
}