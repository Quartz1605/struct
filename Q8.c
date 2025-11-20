#include<stdio.h>
#include<stdlib.h>

//Palindrome check in LL...

//Algo is 
// 1. find middle of the LL using slow fast and reverse the rest half
// then check whether both have the same data or not
// if not return 0 if yes return 1;

typedef struct Node{
    int val;
    struct Node* next;
} Node;

Node* createNode(int val){
    
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    return node;
}

Node* createLL(int val, Node* head){
    
  if (!head) return createNode(val);

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = createNode(val);
    return head;
}

Node* reverseLL(Node* head){
    
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}

int palindromeCheck(Node* head){
    
  if (head == NULL || head->next == NULL) return 1;

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* second = reverseLL(slow);

    Node* first = head;
    Node* temp = second;

    while (temp != NULL) {
        if (temp->val != first->val) return 0;

        temp = temp->next;
        first = first->next;
    }

    return 1;
}

int main(){
    Node* head = NULL;
    head = createLL(1, head);
    head = createLL(2, head);
    head = createLL(3, head);

    if (palindromeCheck(head)) {
        printf("hell yeah\n");
    } else {
        printf("fuck y'all\n");
    }
}
