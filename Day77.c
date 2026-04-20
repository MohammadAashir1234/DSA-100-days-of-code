/*Problem Statement
Using BFS or DFS, check if the entire graph is connected.

Input Format
n m
edges

Output Format
CONNECTED
NOT CONNECTED

Sample Input
4 2
1 2
3 4

Sample Output
NOT CONNECTED*/
#include <stdio.h>

#define MAX 100

int queue[MAX], front = 0, rear = 0;

void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX] = {0};
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // undirected
    }

    int visited[MAX] = {0};
    enqueue(1); // start BFS from vertex 1
    visited[1] = 1;

    while (!isEmpty()) {
        int u = dequeue();
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && !visited[v]) {
                visited[v] = 1;
                enqueue(v);
            }
        }
    }

    int connected = 1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            connected = 0;
            break;
        }
    }

    if (connected) printf("CONNECTED\n");
    else printf("NOT CONNECTED\n");

    return 0;
}
