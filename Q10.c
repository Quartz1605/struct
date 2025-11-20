#include <stdio.h>
#include <stdlib.h>

//We same exp wale coeff ki adding bachi hai also wo arranged nahi hai dhangse we will do that later..

//Coeff multiplication..

typedef struct Node
{

  int coeff;
  int exp;
  struct Node *next;

} Node;

Node *createNode(int coeff, int exp)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->coeff = coeff;
  newNode->exp = exp;
  newNode->next = NULL;
  return newNode;
}

Node *insertEnd(Node *head, int coeff, int exp)
{

  Node *temp = createNode(coeff, exp);
  if (head == NULL)
    return temp;

  Node *cur = head;
  while (cur->next != NULL)
    cur = cur->next;

  cur->next = temp;
  return head;
}

Node *addPoly(Node *p1, Node *p2)
{

  Node *result = NULL, *last = NULL;
  Node* temp2 = p2;

  while (p1 != NULL){

    p2 = temp2;

    Node *temp = NULL;

    while (p2 != NULL)
    {

      temp = createNode((p1->coeff * p2->coeff), (p1->exp + p2->exp));
      p2 = p2->next;

      if (result == NULL)
        result = temp;
      else
        last->next = temp;

      last = temp;
    }

    p1 = p1->next;

  }

  return result;

}

void printPoly(Node *head)
{
  while (head)
  {
    printf("%dx^%d", head->coeff, head->exp);
    if (head->next)
      printf(" + ");
    head = head->next;
  }
  printf("\n");
}



int main()
{
  Node *p1 = NULL, *p2 = NULL;

  // Example polynomial 1: 5x^3 + 4x^1 + 2x^0
  p1 = insertEnd(p1, 5, 3);
  p1 = insertEnd(p1, 4, 1);
  p1 = insertEnd(p1, 2, 0);

  // Example polynomial 2: 3x^3 + 1x^2 + 2x^1
  p2 = insertEnd(p2, 3, 3);
  p2 = insertEnd(p2, 1, 2);
  p2 = insertEnd(p2, 2, 1);

  printf("P1: ");
  printPoly(p1);
  printf("P2: ");
  printPoly(p2);

  Node *sum = addPoly(p1, p2);

  // while(sum != NULL){
  //   printf("%d ",sum->coeff);
  //   sum = sum->next;
  // }

  printf("Sum: ");
  printPoly(sum);

  return 0;
}
