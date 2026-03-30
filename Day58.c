/*Problem Statement:
Construct a binary tree from given preorder and inorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains preorder traversal
- Third line contains inorder traversal

Output Format:
- Print postorder traversal of constructed tree

Example:
Input:
5
1 2 4 5 3
4 2 5 1 3

Output:
4 5 2 3 1

Explanation:
Preorder identifies root, inorder splits left and right subtrees.*/
#include <stdio.h>
#include <stdlib.h>

// Define structure for a tree node
struct Node {
    int val;
    struct Node *left, *right;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Search for index of value in inorder[]
int search(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val) return i;
    }
    return -1;
}

// Recursive function to build tree
struct Node* buildTree(int preorder[], int inorder[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd) return NULL;

    // Pick current node from preorder
    struct Node* root = newNode(preorder[*preIndex]);
    (*preIndex)++;

    // If leaf node
    if (inStart == inEnd) return root;

    // Find root in inorder
    int inIndex = search(inorder, inStart, inEnd, root->val);

    // Build left and right subtrees
    root->left = buildTree(preorder, inorder, inStart, inIndex - 1, preIndex);
    root->right = buildTree(preorder, inorder, inIndex + 1, inEnd, preIndex);

    return root;
}

// Postorder traversal
void postorder(struct Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

// Driver code
int main() {
    int N;
    scanf("%d", &N);

    int preorder[N], inorder[N];
    for (int i = 0; i < N; i++) scanf("%d", &preorder[i]);
    for (int i = 0; i < N; i++) scanf("%d", &inorder[i]);

    int preIndex = 0;
    struct Node* root = buildTree(preorder, inorder, 0, N - 1, &preIndex);

    postorder(root);
    printf("\n");

    return 0;
}