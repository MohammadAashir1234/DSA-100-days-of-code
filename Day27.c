/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

int getLength(struct Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    struct Node* temp1 = head1;
    struct Node* temp2 = head2;
    if (len1 > len2) {
        for (int i = 0; i < len1 - len2; i++) temp1 = temp1->next;
    } else {
        for (int i = 0; i < len2 - len1; i++) temp2 = temp2->next;
    }
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1 == temp2) return temp1;  
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return NULL;
}

int main() {
    int n, m, value;
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head1 = insertEnd(head1, value);
    }
    scanf("%d", &m);
    struct Node* temp2 = NULL;
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        if (i == 0) {
            head2 = insertEnd(head2, value);
            temp2 = head2;
        } else {
            temp2 = insertEnd(temp2, value);
        }
    }
    struct Node* curr1 = head1;
    while (curr1 != NULL) {
        if (curr1->data == value) {  
            temp2->next = curr1;     
            break;
        }
        curr1 = curr1->next;
    }

    struct Node* intersection = findIntersection(head1, head2);

    if (intersection != NULL) {
        printf("%d\n", intersection->data);
    } else {
        printf("No Intersection\n");
    }

    return 0;
}