#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
  
  int coeff;
  int exp;
  struct Node* next;

}Node;


Node* createNode(int coeff,int exp){

  Node* temp = (Node*)malloc(sizeof(Node));
  temp->coeff = coeff;
  temp->exp = exp;
  temp->next = NULL;

  return temp;
} 

Node* insertEnd(Node* head,int coeff,int exp){

  if(head == NULL) return createNode(coeff,exp);

  Node* temp = head;

  while(temp->next != NULL){
    temp = temp->next;
  }

  temp->next = createNode(coeff,exp);

  return head;


} 

Node* addPoly(Node* p1, Node* p2){

  Node* result = NULL; Node* last = NULL;
  Node* temp;

  while(p1 != NULL && p2 != NULL){

    if(p1->exp == p2->exp){

      temp = createNode((p1->coeff+p2->coeff),p1->exp);
      p1 = p1->next;
      p2 =  p2->next;
    
    }

    else if(p1->exp > p2->exp){
      temp = createNode(p1->coeff,p1->exp);
      p1 = p1->next;
    }

    else if(p1->exp < p2->exp){
      temp = createNode(p2->coeff,p2->exp);
      p2 = p2->next;
    }

    if(result == NULL){
      result = temp;
      last = temp;
    
    }else{
      
      last->next = temp;
      last = temp;
    
    }

  }

  while(p1){

      temp = createNode(p1->coeff,p1->exp);
      last->next = temp;
      last = temp;
      p1 = p1->next;

    }

    while(p2){

      temp = createNode(p2->coeff,p2->exp);
      last->next = temp;
      last = temp;
      p2 = p2->next;

    }

  return result;

}

void printPoly(Node* head){

  while(head){
    
    printf("%dx^%d+",head->coeff,head->exp);
    head = head->next;

  }

}


int main(){

  Node *p1 = NULL, *p2 = NULL;

    
  p1 = insertEnd(p1, 5, 3);
  p1 = insertEnd(p1, 4, 1);
  p1 = insertEnd(p1, 2, 0);

  printPoly(p1);
  printf("\n");

    
  p2 = insertEnd(p2, 3, 3);
  p2 = insertEnd(p2, 1, 2);
  p2 = insertEnd(p2, 2, 1);

  printPoly(p2);
  printf("\n");

  Node* sum = addPoly(p1,p2);

  printPoly(sum);



}


