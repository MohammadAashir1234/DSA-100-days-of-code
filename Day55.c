/*Problem Statement:
Print the nodes visible when the binary tree is viewed from the right side.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print right view nodes

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
1 3 6

Explanation:
At each level, the rightmost node is visible from the right view.*/
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;

// Queue structure for building tree
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

// Print Right View
void rightView(Node* root) {
    if (root == NULL) return;

    Queue q = { .front = 0, .rear = 0 };
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        int size = q.rear - q.front;

        for (int i = 0; i < size; i++) {
            Node* curr = dequeue(&q);

            // Rightmost element of this level
            if (i == size - 1) {
                printf("%d ", curr->val);
            }

            if (curr->left) enqueue(&q, curr->left);
            if (curr->right) enqueue(&q, curr->right);
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

    Node* root = buildTree(arr, N);
    rightView(root);

    return 0;
}