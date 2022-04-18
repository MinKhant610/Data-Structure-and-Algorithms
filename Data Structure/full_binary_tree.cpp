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

bool isFullBinary (struct Node *root) {
    if (root == NULL) {
        return true;
    }
    
    if ( (root->left == NULL) && (root->right == NULL) ) {
        return true;
    }

    if ( (root->left) && (root->right) ) {
        return ( isFullBinary(root->left) && isFullBinary(root->right) ) ;
    }

    return false;
}

int main () {

    struct Node *root = NULL ;
    root = newNode(8);
    root->left = newNode (10);
    root->right = newNode (3);
    root->right->left = newNode (11);

    if ((isFullBinary(root)))
        cout << "It is Full Binary Tree \n";
    else 
        cout << "It is not Full Binary Tree \n";
        
    return 0;
}