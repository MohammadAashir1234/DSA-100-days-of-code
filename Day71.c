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
#include <stdlib.h>
#include <string.h>

#define EMPTY -1

// Hash function (basic modulo)
int hash(int key, int m) {
    return key % m;
}

// Insert key into hash table using quadratic probing
void insert(int *table, int m, int key) {
    int h = hash(key, m);
    for (int i = 0; i < m; i++) {
        int pos = (h + i * i) % m;
        if (table[pos] == EMPTY) {
            table[pos] = key;
            return;
        }
    }
    // Table full (not expected in typical usage)
}

// Search key in hash table using quadratic probing
int search(int *table, int m, int key) {
    int h = hash(key, m);
    for (int i = 0; i < m; i++) {
        int pos = (h + i * i) % m;
        if (table[pos] == EMPTY) return 0; // not found
        if (table[pos] == key) return 1;   // found
    }
    return 0;
}

int main() {
    int m, q;
    scanf("%d", &m); // table size
    scanf("%d", &q); // number of operations

    int *table = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) table[i] = EMPTY;

    char op[10];
    int key;
    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);
        if (strcmp(op, "INSERT") == 0) {
            insert(table, m, key);
        } else if (strcmp(op, "SEARCH") == 0) {
            if (search(table, m, key))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    free(table);
    return 0;
}
