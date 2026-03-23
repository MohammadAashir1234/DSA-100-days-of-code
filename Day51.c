/*Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
6 2 8 0 4 7 9
2 8

Output:
6*/
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

// Insert into BST
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->val) root->left = insertIntoBST(root->left, val);
    else root->right = insertIntoBST(root->right, val);
    return root;
}

// Find LCA in BST
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, int p, int q) {
    while (root != NULL) {
        if (p < root->val && q < root->val) {
            root = root->left;   // both in left subtree
        } else if (p > root->val && q > root->val) {
            root = root->right;  // both in right subtree
        } else {
            return root;         // split point → LCA
        }
    }
    return NULL;
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int p, q;
    scanf("%d %d", &p, &q);

    // Build BST from given values
    struct TreeNode* root = NULL;
    for (int i = 0; i < N; i++) {
        root = insertIntoBST(root, arr[i]);
    }

    struct TreeNode* lca = lowestCommonAncestor(root, p, q);
    if (lca != NULL) {
        printf("%d\n", lca->val);
    }

    return 0;
}