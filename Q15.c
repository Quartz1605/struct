//BST tree construction and its traversal..

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

  if(root == NULL){
    return createNode(val);
  }

  if(val < root->data){
    root->left = insert(root->left,val);
  }

  else if(val > root->data){
    root->right = insert(root->right,val);
  }

  return root;


}

void inorder(Node* root){

  if(root != NULL){
    
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);

  }

}

void preorder(Node* root){
  
  if(root != NULL){

    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);

  }

}

void postorder(Node* root){
  
  if(root != NULL){

    
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);

  }

}

int main(){

  Node* root = NULL;

  root = insert(root,5);
  root = insert(root,10);
  root = insert(root,3);
  root = insert(root,2);
  root = insert(root,4);

  postorder(root);




}
