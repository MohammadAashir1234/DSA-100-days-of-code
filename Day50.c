/*Problem: BST Search

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

// Recursive BST search
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (root == NULL || root->val == val) {
        return root;  // either not found (NULL) or found the node
    }

    if (val < root->val) {
        return searchBST(root->left, val);
    } else {
        return searchBST(root->right, val);
    }
}

// Insertion helper (to build BST for testing)
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->val) root->left = insertIntoBST(root->left, val);
    else root->right = insertIntoBST(root->right, val);
    return root;
}

int main() {
    /* Build example BST:
             4
            / \
           2   7
          / \
         1   3
    */
    struct TreeNode* root = NULL;
    root = insertIntoBST(root, 4);
    insertIntoBST(root, 2);
    insertIntoBST(root, 7);
    insertIntoBST(root, 1);
    insertIntoBST(root, 3);

    int target = 2;
    struct TreeNode* result = searchBST(root, target);

    if (result != NULL) {
        printf("Found node with value %d\n", result->val);
    } else {
        printf("Value %d not found in BST\n", target);
    }

    return 0;
}