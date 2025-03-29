#include <stdio.h>
#include <limits.h>
#include <stdbool.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

bool isBSTUtil(struct Node* node, int min, int max) {
   
    if (node == NULL)
        return true;

    if (node->data < min || node->data > max)
        return false;

  
    return isBSTUtil(node->left, min, node->data - 1) &&
           isBSTUtil(node->right, node->data + 1, max);
}


bool isBST(struct Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}


int main() {
    struct Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);
    root->left->left = newNode(1);
    root->left->right = newNode(8);
    root->right->right = newNode(17);

    if (isBST(root))
        printf("The tree is a Binary Search Tree.\n");
    else
        printf("The tree is not a Binary Search Tree.\n");

    return 0;
}
