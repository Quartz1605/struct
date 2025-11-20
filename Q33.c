//create BT and traverse it level by level..

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
  int data;
  struct Node* left;
  struct Node* right;
}Node;


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

void levelTraversal(Node* root) {

  int front = 0;
  int rear = 0;

  Node* queue[100];
  
  queue[rear++] = root;

  while(front < rear){
    
    Node* curr = queue[front++];
    printf("%d ",curr->data);
    
    if(curr->left) queue[rear++] = curr->left;
    if(curr->right) queue[rear++] = curr->right;

  }
 
}

int main(){

  int arr[] = {1,2,3,4,5,6,7};
  int n = sizeof(arr)/sizeof(arr[0]);

  Node* root = createBT(arr,0,n);

  levelTraversal(root);

 


}




/*if (root == NULL) return;

    
    int front = 0, rear = 0;
    int maxNodes = 100;
    Node* queue[100];

    queue[rear++] = root;

    while (front < rear) {
      
      Node* curr = queue[front++];
      printf("%d ", curr->data);
      if (curr->left != NULL) queue[rear++] = curr->left;
      if (curr->right != NULL) queue[rear++] = curr->right;

    }*/