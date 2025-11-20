// Add two linked list numbers... //Very Good problem

//Algo is reverse the list then add and then again reverse the list..

#include<stdio.h>
#include<stdlib.h>


typedef struct Node
{

  int data;
  struct Node *next;

} Node;

Node* createNode(int val)
{

  Node *node = (Node *)malloc(sizeof(Node));
  node->data = val;
  node->next = NULL;

  return node;
}

Node* insertEnd(Node *head, int data)
{

  if (!head)
    return createNode(data);

  Node *temp = head;

  while (temp->next != NULL)
  {
    temp = temp->next;
  }

  Node *newNode = createNode(data);

  temp->next = newNode;

  return head;
}


Node* reverseLL(Node* head){

  Node* prev = NULL;
  Node* curr = head;
  Node* next = NULL;

  while(curr != NULL){

    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;

  }

  //printf("hey");

  return prev;

}

Node* add(Node* a,Node* b,int carry){

  if(a == NULL && b == NULL && carry == 0) return NULL;

  int sum = carry;

  if(a) sum += a->data; //if a and b mat bhoolna warna issue aayega..
  if(b) sum += b->data;

  Node* node = createNode(sum%10);

  node->next = add(a ? a->next : NULL,b ? b->next : NULL, sum/10);

  return node;


}

Node* addNumbers(Node* a, Node* b){

  a = reverseLL(a);
  b = reverseLL(b);

  Node* ans = add(a,b,0);

  return reverseLL(ans);

}




void displayLL(Node *head){

  Node *temp = head;

  while (temp != NULL)
  {
    printf("%d", temp->data);

    if (temp->next != NULL)
      printf("<->");

    temp = temp->next;
  }

}


int main(){



  Node* list1 = NULL; Node* list2 = NULL;

  list1 = insertEnd(list1,7);
  list1 = insertEnd(list1,2);
  list1 = insertEnd(list1,3);
  list1 = insertEnd(list1,3);

  list2 = insertEnd(list2,5);
  list2 = insertEnd(list2,7);
  list2 = insertEnd(list2,3);

  Node* r = addNumbers(list1,list2);

  displayLL(r);
  
  
  

}