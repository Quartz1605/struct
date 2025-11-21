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

int preIndex = 0;



int findIndex(int inorder[],int start,int end,int n){

  for(int i=start;i<=end;i++){

    if(inorder[i] == n) return i;

  }

  return -1;

}




Node* buildTree(int preorder[],int inorder[],int start,int end){

  
  
  if(end < start) return NULL;

  int val = preorder[preIndex++];
  

  Node* node = createNode(val);

  if(start == end) return node;

  int pos = findIndex(inorder,start,end,val);

  node->left = buildTree(preorder,inorder,start,pos-1);
  node->right = buildTree(preorder,inorder,pos+1,end);

  return node;

}

void postorder(Node* root){

  

  if(root != NULL){
   

    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
  
  }

}


int main() {

    int n;
    int inorder[] = {4,2,5,1,6,3,7};
    int preorder[] = {1,2,4,5,3,6,7};

    Node* root = buildTree(preorder, inorder, 0, 6);

    
    postorder(root);
    printf("\n");

    return 0;
}