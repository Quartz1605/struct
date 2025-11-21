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

Node* insertBST(Node* root,int data){

  if(root == NULL) return createNode(data);

  if(data < root->data){
    root->left = insertBST(root->left,data);
  }

  if(data > root->data){
    root->right = insertBST(root->right,data);
  }

  return root;

}

void inorder(Node* root){

  if(root ==  NULL) return;

  inorder(root->right);
  printf("%d ",root->data);
  inorder(root->left);

}


int main(){

  Node* root = NULL;

  root = insertBST(root,3);
  root = insertBST(root,4);
  root = insertBST(root,7);
  root = insertBST(root,2);
  root = insertBST(root,5);
  root = insertBST(root,8);
  root = insertBST(root,6);

  inorder(root);
  

}