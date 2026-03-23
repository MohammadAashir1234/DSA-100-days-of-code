/*Problem: Count Leaf Nodes

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

// Recursive function to count leaf nodes
int countLeafNodes(struct TreeNode* root) {
    if (root == NULL) return 0;

    if (root->left == NULL && root->right == NULL) {
        return 1;  // this node is a leaf
    }

    return countLeafNodes(root->left) + countLeafNodes(root->right);
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

    printf("Number of leaf nodes: %d\n", countLeafNodes(root)); // Output: 3 (nodes 3, 4, 5)

    return 0;
}