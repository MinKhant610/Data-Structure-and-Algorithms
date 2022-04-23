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

int depth (struct Node *node) {
    int dep = 0;
    while (node != NULL){
        dep++ ;
        node = node->left ;
    }
    return dep;
}

bool checkPerfectbinary (Node *root, int depth, int  level = 0) {
    if (root == NULL) {
        return true;
    }

    if (root->left == NULL && root->right == NULL) {
        return (depth == level +1);
    }

    if (root->left == NULL || root->right == NULL) {
        return false;
    }

    return (checkPerfectbinary(root->left, depth, level +1) &&
            checkPerfectbinary(root->right, depth, level + 1));
}

int main () {
    struct Node *root = NULL ;
    root = newNode(8);
    root->left = newNode (10);
    root->right = newNode (3);
    //root->right->left = newNode (11);

    int dep = depth(root);

    if ((checkPerfectbinary(root, dep)))
        cout << "It is Perfect Binary Tree \n";
    else 
        cout << "It is not Perfect Binary Tree \n";
        
    return 0;
}