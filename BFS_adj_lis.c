#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
}Node;

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
};

int queue[100];
int front=0;
int rear = 0;
struct Node* adj[100];   
int visited[100]; 


void enqueue(int value){
  queue[rear++] = value;
}

int dequeue(){
  return queue[front++];
}

int isEmpty(){
  
  if(front == rear){
    return 1;
  }else{
    return 0;
  }

}

void bfs(int v){

  visited[v] = 1;
  
  enqueue(v);

  while(!isEmpty()){

    int vertex = dequeue();
    printf("%d ",vertex);

    Node* temp = adj[vertex];

    while(temp != NULL){

      int neigh = temp->vertex;

      if(!visited[neigh]){
        
        visited[neigh] = 1;
        enqueue(neigh);

      }

      temp = temp->next;

    }


  }

}



int main(){

  int vertices;
  int edges;

  printf("Enter the number of vertices\n");
  scanf("%d",&vertices);

  printf("Enter the number of edges\n");
  scanf("%d",&edges);

  printf("Enter the edges pair u v\n");

  

  for(int i=0;i<edges;i++){
    int u,v;
    scanf("%d %d",&u,&v);

    Node* node = createNode(v);

    node->next = adj[u];
    adj[u] = node;

  }

  bfs(0);

  return 0;



}