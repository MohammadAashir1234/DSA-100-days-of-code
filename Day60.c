/*Problem Statement:
Check whether a given binary tree satisfies the Min-Heap property.

Input Format:
- First line contains integer N
- Second line contains level-order traversal

Output Format:
- Print YES if valid Min-Heap, otherwise NO

Example:
Input:
7
1 3 5 7 9 8 10

Output:
YES

Explanation:
Each parent node must be smaller than its children.*/
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
// Check if tree is complete
int isComplete(struct Node* root) {
    if (!root) return 1;
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int flag = 0; // Flag to indicate if we have seen a non-full node
    while (front < rear) {
        struct Node* curr = queue[front++];
        if (curr->left) {
            if (flag) return 0; // If we have seen a non-full node, tree is not complete
            queue[rear++] = curr->left;
        } else {
            flag = 1; // Mark that we have seen a non-full node
        }
        if (curr->right) {
            if (flag) return 0; // If we have seen a non-full node, tree is not complete
            queue[rear++] = curr->right;
        } else {
            flag = 1; // Mark that we have seen a non-full node
        }
    }
    return 1;
}
// Check if tree satisfies Min-Heap property
int isMinHeap(struct Node* root) {
    if (!root) return 1;
    if (root->left && root->val > root->left->val) return 0;
    if (root->right && root->val > root->right->val) return 0;
    return isMinHeap(root->left) && isMinHeap(root->right);
}
int main() {
    int N;
    scanf("%d", &N);
    if (N == 0) {
        printf("YES\n");
        return 0;
    }
    struct Node* root = NULL;
    struct Node* queue[100];
    int front = 0, rear = 0;
    for (int i = 0; i < N; i++) {
        int val;
        scanf("%d", &val);
        struct Node* node = newNode(val);
        if (!root) {
            root = node;
        } else {
            if (queue[front]->left == NULL) {
                queue[front]->left = node;
            } else {
                queue[front]->right = node;
                front++;
            }
        }
        queue[rear++] = node;
    }
    if (isComplete(root) && isMinHeap(root)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
