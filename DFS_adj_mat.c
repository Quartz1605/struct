#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 10


void DFS(int graph[MAX][MAX],bool visited[],int vertex,int n){

  visited[vertex] = true;
  printf("%d ",vertex);

  for(int i=0;i<n;i++){
    if(graph[vertex][i] == 1 && visited[i] == false){
      DFS(graph,visited,i,n);
    }
  }

}


int main(){

  int n;

  printf("Enter the number of vertices \n");
  scanf("%d",&n);

  int graph[n][n];

  printf("Enter the adjacency matrices elements \n");
  
  for(int i=0;i<n;i++){
    
    for(int j=0;j<n;j++){

      scanf("%d",&graph[i][j]);

    }

  }

  bool visited[n];
  
  for(int i=0;i<n;i++){
    visited[i] = false;
  }

  DFS(graph,visited,0,n);




}