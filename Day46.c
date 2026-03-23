/*Problem: Level Order Traversal

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

// Level Order Traversal using BFS
void levelOrder(struct TreeNode* root) {
    if (root == NULL) {
        printf("[]\n");
        return;
    }

    // Simple queue implementation
    struct TreeNode* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root;
    printf("[");

    while (front < rear) {
        int levelSize = rear - front;
        printf("[");
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];
            printf("%d", node->val);
            if (i < levelSize - 1) printf(",");

            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }
        printf("]");
        if (front < rear) printf(",");
    }
    printf("]\n");
}

int main() {
    /* Example tree: [3,9,20,null,null,15,7]
             3
            / \
           9   20
              /  \
             15   7
    */

    struct TreeNode* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    printf("Level Order Traversal:\n");
    levelOrder(root); // Output: [[3],[9,20],[15,7]]

    return 0;
}