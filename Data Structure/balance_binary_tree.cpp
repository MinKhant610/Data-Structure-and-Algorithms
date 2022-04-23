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

bool isBalancebinary(struct Node *root, int *heigh) {
    int left = 0 , right = 0;
    int leftH = 0 , rightH = 0 ;

    if (root == NULL){
        *heigh = 0;
        return true;
    }

    left = isBalancebinary (root->left, &leftH);
    right = isBalancebinary (root->right, &rightH);

    *heigh = (leftH > rightH ? leftH : rightH) + 1 ;

    if ((leftH - rightH >= 2) || (rightH - leftH >= 2)){
        return false;
    }else {
        return left && right ;
    }
}

int main () {
    int heigh = 0;
    struct Node *root = NULL ;
    root = newNode(8);
    root->left = newNode (10);
    root->right = newNode (3);
    root->right->left = newNode (11);
    //root->right->left->right = newNode (31);

    if (isBalancebinary(root, &heigh))
        cout << "It is Balance Binary Tree \n";
    else 
        cout << "It is not Balance Binary Tree \n";
        
    return 0;
}