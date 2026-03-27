/*Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Node structure
typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;

// Queue for building tree
typedef struct Queue {
    Node* data[1000];
    int front, rear;
} Queue;

void enqueue(Queue* q, Node* node) {
    q->data[q->rear++] = node;
}
Node* dequeue(Queue* q) {
    return q->data[q->front++];
}
int isEmpty(Queue* q) {
    return q->front == q->rear;
}

// Create new node
Node* newNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level-order input
Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    Node* root = newNode(arr[0]);
    Queue q = { .front = 0, .rear = 0 };
    enqueue(&q, root);

    int i = 1;
    while (!isEmpty(&q) && i < n) {
        Node* curr = dequeue(&q);

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(&q, curr->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(&q, curr->right);
        }
        i++;
    }
    return root;
}

// Structure for vertical order storage
typedef struct VNode {
    int val;
    struct VNode* next;
} VNode;

typedef struct {
    VNode* list;
} Column;

// Recursive traversal
void verticalTraversal(Node* root, Column cols[], int hd, int* minHd, int* maxHd) {
    if (root == NULL) return;

    if (hd < *minHd) *minHd = hd;
    if (hd > *maxHd) *maxHd = hd;

    VNode* newv = (VNode*)malloc(sizeof(VNode));
    newv->val = root->val;
    newv->next = NULL;

    if (cols[hd + 500].list == NULL) {
        cols[hd + 500].list = newv;
    } else {
        VNode* temp = cols[hd + 500].list;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newv;
    }

    verticalTraversal(root->left, cols, hd - 1, minHd, maxHd);
    verticalTraversal(root->right, cols, hd + 1, minHd, maxHd);
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

    Node* root = buildTree(arr, N);

    Column cols[1000];
    for (int i = 0; i < 1000; i++) cols[i].list = NULL;

    int minHd = INT_MAX, maxHd = INT_MIN;
    verticalTraversal(root, cols, 0, &minHd, &maxHd);

    for (int hd = minHd; hd <= maxHd; hd++) {
        VNode* temp = cols[hd + 500].list;
        while (temp != NULL) {
            printf("%d ", temp->val);
            temp = temp->next;
        }
        printf("\n");
    }

    return 0;
}