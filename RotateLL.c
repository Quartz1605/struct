// rotate LL by K positions..

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



Node* rotateLL(Node* head,int k){

  
  
  while(k != 0){

    //printf("%d",k);

    Node* temp = head;

    while(temp->next->next != NULL){
      temp = temp->next;
    }

    Node* node = createNode(temp->next->data);

    temp->next = NULL;

    node->next = head;
    head = node;

    k = k-1;

  }

  return head;
  

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
  
  Node* list1 = NULL;

  list1 = insertEnd(list1,7);
  list1 = insertEnd(list1,1);
  list1 = insertEnd(list1,6);
  list1 = insertEnd(list1,4);

  //displayLL(list1);
  printf("\n");

  Node* ans =  rotateLL(list1,1);

  displayLL(ans);


}