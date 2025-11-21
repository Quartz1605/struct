#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;


Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int isEqual(Node* a, Node* b) {
    if (a == NULL && b == NULL)
        return 1;

    if (a == NULL || b == NULL)
        return 0;

    return (a->data == b->data) &&
           isEqual(a->left, b->left) &&
           isEqual(a->right, b->right);
}


void mirror(Node* root) {
    if (!root) return;


    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}


void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}


int main() {


    Node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);

    
    Node* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);

  
    if (isEqual(root1, root2))
        printf("Trees are equal\n");
    else
        printf("Trees are NOT equal\n");

   
    printf("Inorder of Tree1 before mirroring: ");
    inorder(root1);
    printf("\n");

    mirror(root1);

    printf("Inorder of Tree1 after mirroring:  ");
    inorder(root1);
    printf("\n");

    return 0;
}
