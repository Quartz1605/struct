#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createRec() {
    int x;
    scanf("%d", &x);
    if (x == -1) return NULL;
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = createRec();
    return temp;
}

void displayRec(Node* head) {
    if (!head) return;
    printf("%d ", head->data);
    displayRec(head->next);
}

int lengthRec(Node* head) {
    if (!head) return 0;
    return 1 + lengthRec(head->next);
}

Node* reverseRec(Node* head) {
    if (!head || !head->next) return head;
    Node* rest = reverseRec(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

int main() {
    Node* head = createRec();
    displayRec(head);
    printf("\nLength: %d\n", lengthRec(head));
    head = reverseRec(head);
    displayRec(head);
    return 0;
}
