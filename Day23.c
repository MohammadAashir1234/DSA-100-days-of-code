/*Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged.*/
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
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
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
struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;
    struct Node* mergedHead = NULL;
    struct Node* mergedTail = NULL;
    if (head1->data < head2->data) {
        mergedHead = head1;
        head1 = head1->next;
    } else {
        mergedHead = head2;
        head2 = head2->next;
    }
    mergedTail = mergedHead;
    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            mergedTail->next = head1;
            head1 = head1->next;
        } else {
            mergedTail->next = head2;
            head2 = head2->next;
        }
        mergedTail = mergedTail->next;
    }
    if (head1 != NULL) {
        mergedTail->next = head1;
    } else {
        mergedTail->next = head2;
    }

    return mergedHead;
}
int main() {
    int n1, n2, val;
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    printf("Enter number of elements in first sorted list: ");
    scanf("%d", &n1);
    printf("Enter %d elements (sorted): ", n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &val);
        list1 = insertEnd(list1, val);
    }
    printf("Enter number of elements in second sorted list: ");
    scanf("%d", &n2);
    printf("Enter %d elements (sorted): ", n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &val);
        list2 = insertEnd(list2, val);
    }
    printf("First List: ");
    printList(list1);
    printf("Second List: ");
    printList(list2);
    struct Node* merged = mergeLists(list1, list2);
    printf("Merged Sorted List: ");
    printList(merged);
    return 0;
}