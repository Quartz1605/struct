#include <stdio.h>
#include <stdlib.h>

//DLL operations..

typedef struct Node
{

  int data;
  struct Node *prev;
  struct Node *next;

} Node;

Node *createNode(int data)
{

  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  node->prev = NULL;

  return node;
}

Node *insertEnd(Node *head, int data)
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
  newNode->prev = temp;

  return head;
}

Node *afterPos(Node *head, int data, int pos)
{

  if (!head)
    return createNode(data);

  Node *temp = head;

  while (pos - 1 != 0)
  {
    temp = temp->next;
    pos--;
  }

  Node *newNode = createNode(data);

  if (temp->next)
  {

    newNode->next = temp->next;

    temp->next->prev = newNode;
  }

  temp->next = newNode;

  newNode->prev = temp;

  return head;
}

//Basically we are swapping nodes ka data and not nodes..

Node *sortDLL(Node *head)
{

  if(!head) return NULL;

  Node* temp2 = head;

  while(temp2 != NULL){

    Node* min = temp2;

    Node* temp = temp2->next;

    while(temp != NULL){
      
      if(temp->data < min->data){

        min = temp;

      }

      temp = temp->next;

    }

    if(min != temp2){

      int temp3 = temp2->data;
      temp2->data = min->data;
      min->data = temp3;
    }

    temp2 = temp2->next;

  }

  return head;

}

Node* concatenateLists(Node* list1,Node* list2){

  //if sorted concat bola toh just sort kardo end mein..

  if(!list1) return list2;
  if(!list2) return list1;

  Node* temp = list1;

  while(temp->next != NULL){

    temp = temp->next;

  }

  temp->next = list2;
  list2->prev = temp;

  return list1;

}

void displayLL(Node* head){


  Node* temp = head;

  while(temp != NULL){
    printf("%d",temp->data);

    if(temp->next != NULL) printf("<->");

    temp = temp->next;
  }

}

int main(){

  Node* list1 = NULL; Node* list2 = NULL;

  list1 = insertEnd(list1,3);
  list1 = insertEnd(list1,4);
  list1 = insertEnd(list1,5);
  list1 = insertEnd(list1,7);
  list1 = insertEnd(list1,2);

  list1 = afterPos(list1,17,2);

  //list1 = sortDLL(list1);

  displayLL(list1);

}


