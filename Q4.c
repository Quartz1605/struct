//KQueues
#include<stdio.h>
#include<stdlib.h>


#define MAX 10
#define n 2

int arr[30];

int front[n];
int rear[n];

int queueSize = MAX/n;


void init(){
  
  for(int i=0;i<n;i++){
    front[i] = rear[i] = (i*queueSize); 
  }

}

void enqueue(int x,int q){

  if(rear[q] == (q+1)*queueSize){
    printf("queue %d overflow",q);
    return;
  }

  
  arr[rear[q]] = x;
  rear[q]++;

}

int dequeue(int q){

  if(front[q] > rear[q]){

    printf("Queue %d underflow",q);
    return -1;

  }
  
  int val = arr[front[q]];
  front[q]++;

  return val;

}

void display(int q){

  for(int i=front[q];i<rear[q];i++){
    printf("%d ",arr[i]);
  }

}

void displayAll(){
  
  for(int i=0;i<MAX;i++){
    printf("%d ",arr[i]);
  }

}


int main(){

  init();

  // enqueue(1,0);
  // enqueue(7,0);
  // enqueue(9,0);
  // enqueue(10,0);
  // enqueue(11,0);
  

  enqueue(43,1);
  enqueue(4,1);
  enqueue(17,1);
  enqueue(2,1);
  enqueue(16,1);
  enqueue(17,1);

  // dequeue(0);
  // dequeue(0);

  // dequeue(1);
  // dequeue(1);
  // dequeue(1);

  // display(1);

  

}
