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


int countNodes(Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}


int countLeafNodes(Node* root) {
    if (root == NULL) return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}


int countNonLeafNodes(Node* root) {
    if (root == NULL) return 0;

    if (root->left == NULL && root->right == NULL)
        return 0;  

    return 1 + countNonLeafNodes(root->left) + countNonLeafNodes(root->right);
}


int main() {

  

    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Total Nodes: %d\n", countNodes(root));
    printf("Terminal (Leaf) Nodes: %d\n", countLeafNodes(root));
    printf("Non Terminal (Internal) Nodes: %d\n", countNonLeafNodes(root));

    return 0;
}
