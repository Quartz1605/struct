#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* newNode(int x) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

Node* swapPairs(Node* head) {
    if (!head || !head->next) return head;

    Node* newHead = head->next;
    Node* prev = NULL;

    while (head && head->next) {
        Node* nxt = head->next;
        head->next = nxt->next;
        nxt->next = head;

        if (prev) prev->next = nxt;
        prev = head;
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
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);

    head = swapPairs(head);
    printList(head);

    return 0;
}
