#include <stdio.h>
#define MAX 100


int adj[MAX][MAX];   
int visited[MAX];    
int queue[MAX];      
int front = 0, rear = 0;


void enqueue(int x) {
    queue[rear++] = x;
}


int dequeue() {
    return queue[front++];
}


int isEmpty() {
    return front == rear;
}


void BFS(int start, int vertices) {
    visited[start] = 1;
    enqueue(start);

    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);

   
        for (int i = 0; i < vertices; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main() {
    
    int vertices, edges;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
        for (int j = 0; j < vertices; j++)
            adj[i][j] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;   
        
    }

    printf("BFS Traversal starting from 0:\n");
    BFS(0, vertices);

    return 0;
}
