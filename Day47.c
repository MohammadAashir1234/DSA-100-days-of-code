/*Problem: Height of Binary Tree

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/
#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Utility function to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Recursive function to calculate height of binary tree
int height(struct TreeNode* root) {
    if (root == NULL) {
        return 0;  // empty tree has height 0
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {
    /* Example tree:
             1
            / \
           2   3
          / \
         4   5
    */

    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Height of the binary tree: %d\n", height(root)); // Output: 3

    return 0;
}