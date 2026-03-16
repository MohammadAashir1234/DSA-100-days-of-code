/*Problem Statement:
Construct a Binary Tree from the given level-order traversal.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers (-1 represents NULL)

Output Format:
- Print inorder traversal of the constructed tree

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
4 2 5 1 3 6*/
#include <stdio.h>
#include <stdlib.h>
// Tree node structure
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};
// Function to create a new tree node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// Function to construct binary tree from level-order traversal
struct TreeNode* constructTree(int* arr, int n)
{
    if (n == 0) return NULL;
    struct TreeNode* root = createNode(arr[0]);
    struct TreeNode* queue[n];
    int front = 0, rear = 0;
    queue[rear++] = root;
    for (int i = 1; i < n; i++) {
        struct TreeNode* current = queue[front++];
        if (arr[i] != -1) {
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
        }
        if (++i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        }
    }
    return root;
}
// Function for inorder traversal
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct TreeNode* root = constructTree(arr, n);
    inorderTraversal(root);
    return 0;
}
