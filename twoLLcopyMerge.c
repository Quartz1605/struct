#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* newNode(int x) {
    Node* t = (Node*)malloc(sizeof(Node));
    t->data = x;
    t->next = NULL;
    return t;
}

void insertSorted(Node** head, int x) {
    Node* temp = newNode(x);
    if (*head == NULL || (*head)->data >= x) {
        temp->next = *head;
        *head = temp;
        return;
    }
    Node* p = *head;
    while (p->next && p->next->data < x)
        p = p->next;
    temp->next = p->next;
    p->next = temp;
}

Node* merge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;
    Node* head = NULL;
    if (a->data < b->data) {
        head = a;
        head->next = merge(a->next, b);
    } else {
        head = b;
        head->next = merge(a, b->next);
    }
    return head;
}

int isEqual(Node* a, Node* b) {
    while (a && b) {
        if (a->data != b->data) return 0;
        a = a->next;
        b = b->next;
    }
    return (a == NULL && b == NULL);
}

Node* copyList(Node* head) {
    if (!head) return NULL;
    Node* newHead = newNode(head->data);
    Node* p = newHead;
    head = head->next;
    while (head) {
        p->next = newNode(head->data);
        p = p->next;
        head = head->next;
    }
    return newHead;
}

void printList(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    Node *l1 = NULL, *l2 = NULL;

    insertSorted(&l1, 1);
    insertSorted(&l1, 3);
    insertSorted(&l1, 5);

    insertSorted(&l2, 2);
    insertSorted(&l2, 4);
    insertSorted(&l2, 6);

    Node* merged = merge(l1, l2);
    printList(merged);
    printf("\n");

    printf(isEqual(l1, l2) ? "Equal\n" : "Not Equal\n");

    Node* copy = copyList(l1);
    printList(copy);

    return 0;
}
