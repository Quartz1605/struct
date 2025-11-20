#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[100];   
int visited[100];        


struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}


void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = adj[v];
    while (temp != NULL) {
        int next = temp->vertex;
        if (!visited[next]) {
            DFS(next);
        }
        temp = temp->next;
    }
}

int main() {
    int vertices, edges;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    
    for (int i = 0; i < vertices; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter number of edges\n");
    scanf("%d",&edges);

    printf("Enter edges (u v): \n");
    for (int i = 0; i < edges; i++) {
      int u, v;
      scanf("%d %d", &u, &v);


      struct Node* node = createNode(v);
      node->next = adj[u];
      adj[u] = node;

    }
    

    printf("DFS starting from 0:\n");
    DFS(0);

    return 0;
}
