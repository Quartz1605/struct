/* Given a linked list and a value x, partition it such that all nodes less than x
come before nodes greater than or equal to x. You should preserve the
original relative order of the nodes in each of the two partitions. */

#include <stdio.h>
#include <stdlib.h>


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

Node* sortLL(Node* head){

  Node* temp = head;

  while(temp){

    Node* min = temp;

    Node* temp2 = temp->next;

    while(temp2 != NULL){
      
      if(temp2->data < min->data){
        min = temp2;
      }

      temp2 = temp2->next;
    }

    if(min != temp){
      
      int temp3 = min->data;
      min->data = temp->data;
      temp->data = temp3;

    }

    temp = temp->next;


  }

  return head;
  


}

Node* sortAcctoX(Node* head,int x){

  Node* list1 = NULL;
  Node* list2 = NULL;

  Node* temp = head;

  while(temp != NULL){

    if(temp->data < x){ // "<=" mat daalna pls yahape
      list1 = insertEnd(list1,temp->data);
    }else{
      list2 = insertEnd(list2,temp->data);
    }

    temp = temp->next;

  }

  //list1 = sortLL(list1); No need of sorting spoils tha logic..

  Node* temp2 = list1;

  while(temp2->next != NULL){
    temp2 = temp2->next;
  }

  temp2->next = list2;

  return list1;


}

void displayLL(Node *head)
{

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


  Node* ll = NULL;

  ll = insertEnd(ll,2);
  ll = insertEnd(ll,3);
  ll = insertEnd(ll,2);
  ll = insertEnd(ll,3);
  ll = insertEnd(ll,1);
  ll = insertEnd(ll,3);
  ll = insertEnd(ll,1);


  ll = sortAcctoX(ll,3);

  displayLL(ll);
  


}
