/*Problem Statement
Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input Format
Same as previous.

Output Format
Result of SEARCH operations.

Sample Input
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output
FOUND
NOT FOUND

Explanation
Collisions resolved using i² jumps.*/
#include <stdio.h>
#include <string.h>

#define MAX 100

int table[MAX];
int m;

int hash(int key) {
    return key % m;
}

void insert(int key) {
    int idx = hash(key);
    for (int i = 0; i < m; i++) {
        int newIdx = (idx + i * i) % m;
        if (table[newIdx] == -1) {
            table[newIdx] = key;
            return;
        }
    }
}

int search(int key) {
    int idx = hash(key);
    for (int i = 0; i < m; i++) {
        int newIdx = (idx + i * i) % m;
        if (table[newIdx] == key) return 1;
        if (table[newIdx] == -1) return 0;
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &m);
    scanf("%d", &n);

    for (int i = 0; i < m; i++) table[i] = -1;

    for (int i = 0; i < n; i++) {
        char op[10];
        int key;
        scanf("%s %d", op, &key);
        if (strcmp(op, "INSERT") == 0) insert(key);
        else if (strcmp(op, "SEARCH") == 0) {
            if (search(key)) printf("FOUND\n");
            else printf("NOT FOUND\n");
        }
    }
    return 0;
}
