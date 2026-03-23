/*Problem: BST Insert

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

// Recursive function to insert into BST
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if (root == NULL) {
        return newNode(val);  // create new node if tree is empty
    }

    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }

    return root; // return unchanged root pointer
}

// Inorder traversal to verify BST structure
void inorder(struct TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

int main() {
    struct TreeNode* root = NULL;

    // Insert values into BST
    root = insertIntoBST(root, 5);
    insertIntoBST(root, 3);
    insertIntoBST(root, 7);
    insertIntoBST(root, 2);
    insertIntoBST(root, 4);

    printf("Inorder traversal after insertion: ");
    inorder(root);  // Output: 2 3 4 5 7
    printf("\n");

    return 0;
}
