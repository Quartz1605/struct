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

Node* insert(Node* root,int val){

  if(!root) return createNode(val);

  if(root->data > val){
    root->left = insert(root->left,val);
  }

  if(root->data < val){
    root->right = insert(root->right,val);
  }

  return root;

}

Node* createBT(int tree[],int i,int n){

  if(i >= n) return NULL;

  Node* root = createNode(tree[i]);

  root->left = createBT(tree,2*i+1,n);
  root->right = createBT(tree,2*i+2,n);

  return root;

}


