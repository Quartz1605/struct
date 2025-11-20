// Create binary tree and inorder traversal and count height

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

  Node* root  = createNode(arr[i]);

  root->left = createBT(arr,2*i+1,n);
  root->right = createBT(arr,2*i+2,n);

  return root;

}

void inorder(Node* root){

  if(root != NULL){

    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);

  }

}

int heightTree(Node* root){

  if(root == NULL) return 0;

  int heightLeftTree = heightTree(root->left);
  
  int heightRightTree = heightTree(root->right);

  return 1 + (heightLeftTree > heightRightTree ? heightLeftTree : heightRightTree);


}


int main(){

  int arr[] = {1,2,3,4,5,6,7};
  int n = sizeof(arr)/sizeof(arr[0]);

  Node* root = createBT(arr,0,n);

  inorder(root);
  printf("\n");

  printf("%d ",heightTree(root));


}