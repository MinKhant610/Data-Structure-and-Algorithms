#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node {
    int key;
    struct Node *left, *right;
};

struct Node *newNode (int data) {
    struct Node *node = (struct Node*) malloc (sizeof(struct Node));
    node->key = data ;
    node->left = NULL ;
    node->right = NULL ;
};

int n_node (Node *node) {
    if (node == NULL) {
        return (0);
    }
    return (1 + n_node(node->left) + n_node(node->right));
}

bool isCompleteBinary (Node *root, int index, int num_node) {
    if (root == NULL){
        return true;
    }

    if (index >= num_node) {
        return false;
    }

    return isCompleteBinary(root->left, 2*index + 1, num_node) && 
           isCompleteBinary(root->right, 2*index + 2, num_node);
}

int main () {

    struct Node *root = NULL ;
    root = newNode(8);
    root->left = newNode (10);
    root->right = newNode (3);
    root->left->left = newNode (11);
    //root->right->left = newNode (33);

    int num_node = n_node (root);
    int index = 0 ;

    if ((isCompleteBinary(root,index,num_node)))
        cout << "It is Complete Binary Tree \n";
    else 
        cout << "It is not Complete Binary Tree \n";
        
    return 0;
}