// Create a Binary Tree and perform its all traversals but in non recursive manner..

#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
  
  int data;
  struct Node* left;
  struct Node* right;

}Node;

typedef struct Stack {
  Node* data[100];
  int top;
} Stack;

void initStack(Stack* s) { s->top = -1; }
int isEmpty(Stack* s) { return s->top == -1; }
void push(Stack* s, Node* node) { s->data[++(s->top)] = node; }
Node* pop(Stack* s) { return s->data[(s->top)--]; }
Node* peek(Stack* s) { return s->data[s->top]; }


Node* createNode(int data){

  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return node;

}

Node* createBT(int arr[],int i,int n){

  if(i >= n) return NULL;

  Node* root = createNode(arr[i]);

  root->left = createBT(arr,2*i+1,n);
  root->right = createBT(arr,2*i+2,n);

  return root;

}

/*
  Start from the root.
  Go as left as possible, pushing each node onto the stack.
  When you can’t go left, pop from the stack, process (print) the node, then move to its right child.
  Repeat until both the stack is empty and you have no current node.
*/

void inorderIterative(Node* root) {
  
  Stack s;
  initStack(&s);

  Node* curr = root;

  while(curr != NULL || !isEmpty(&s)){

    while(curr != NULL){
      push(&s,curr);
      curr = curr->left;
    }

    curr = pop(&s);
    printf("%d ",curr->data);
    curr = curr->right;

  }
  
}

/*

Start from the root, push it onto the stack.
While the stack isn’t empty:
Pop a node, process (print) it.
Push its right child (if any), then its left child (if any).
The left child is pushed last so it’s processed first (since stack is LIFO).

*/

void preorderIterative(Node* root){

  Stack s;initStack(&s);

  Node* curr = root;
  push(&s,curr);

  while(!isEmpty(&s)){

    curr = pop(&s);
    printf("%d ",curr->data);
    if(curr->right)push(&s,curr->right);
    if(curr->left)push(&s,curr->left);

  }

}

/*

3. Postorder Traversal (Left, Right, Root)
Logic:

Use two stacks.
Push the root onto the first stack.
While the first stack isn’t empty:
Pop a node from the first stack, push it onto the second stack.
Push its left and right children onto the first stack.
After the first stack is empty, pop nodes from the second stack and process (print) them.

*/

void postOrder(Node* root){

  Stack s1,s2;
  initStack(&s1);
  initStack(&s2);

  push(&s1,root);

  while(!isEmpty(&s1)){

    Node* curr = pop(&s1);
    push(&s2,curr);

    if(curr->left) push(&s1,curr->left);
    if(curr->right) push(&s1,curr->right);
  
  }

  while(!isEmpty(&s2)){
    Node* curr = pop(&s2);
    printf("%d ",curr->data);
  }


}


int main(){


  int arr[] = {1,2,3,4,5,6,7};
  Node* root = createBT(arr,0,sizeof(arr)/sizeof(arr[0]));

  //printf("Inorder (iterative): ");
  inorderIterative(root);

  preorderIterative(root);

  postOrder(root);


}


