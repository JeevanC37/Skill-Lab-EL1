#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int findLargestSubtreeSumUtil(struct Node* root, int* maxSum) {
    if (root == NULL) return 0;

    int leftSum = findLargestSubtreeSumUtil(root->left, maxSum);
    int rightSum = findLargestSubtreeSumUtil(root->right, maxSum);

    int currentSum = root->data + leftSum + rightSum;

    if (currentSum > *maxSum) {
        *maxSum = currentSum;
    }

    return currentSum;
}

int findLargestSubtreeSum(struct Node* root) {
    int maxSum = INT_MIN;
    findLargestSubtreeSumUtil(root, &maxSum);
    return maxSum;
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(-2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(-6);
    root->right->right = newNode(2);
  
    int largestSum = findLargestSubtreeSum(root);
    printf("Largest subtree sum is: %d\n", largestSum);

    return 0;
}
