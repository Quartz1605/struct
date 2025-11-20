

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{

  int data;
  struct Node *next;

} Node;

Node *createNode(int val)
{

  Node *node = (Node *)malloc(sizeof(Node));
  node->data = val;
  node->next = NULL;

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

  return head;
}

Node *removeDuplicates(Node *head)
{

  Node *temp = head;

  while (temp->next != NULL)
  {

    Node *temp2 = temp;

    if (temp2->data == temp2->next->data)
    {

      temp->next = temp->next->next;
    }
    else
    {
      temp = temp->next;
    }
  }

  return head;
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

int main()
{

  Node *list1 = NULL;

  list1 = insertEnd(list1, 1);
  list1 = insertEnd(list1, 2);
  list1 = insertEnd(list1, 2);
  list1 = insertEnd(list1, 3);
  list1 = insertEnd(list1, 3);
  list1 = insertEnd(list1, 4);
  list1 = insertEnd(list1, 5);
  list1 = insertEnd(list1, 5);
  // list1 = insertEnd(list1,6);

  // list1 = afterPos(list1,17,2);

  list1 = removeDuplicates(list1);

  displayLL(list1);
}