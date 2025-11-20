#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct Queue{
  int front;
  int rear;
  int capacity;
  int *arr;
}Queue;


Queue* createQueue(int capacity){

  Queue* queue = (Queue*)malloc(sizeof(Queue));
  queue->front = -1;
  queue->rear = -1;
  queue->capacity = capacity;
  queue->arr = (int*)malloc(sizeof(int)*capacity);

  return queue;

}


void enqueue(int val, Queue* q){

  if(isFull(q)){
    return;
  }

  if(q->front == -1){
    q->front = 0;
  }

  q->rear = (queue->rear+1)%(q->capacity);

  q->arr[q->rear] = val;

}


int dequeue(Queue* queue){

  if(isEmpty(queue)){
    return 0;
  }

  int val = queue->arr[queue->front];
  
  if(q->rear == q->front){
    q-rear = q->front = -1;
  }else{
    q->front = (q->front+1)%(q->capacity);
  }

  return val;

}

bool isEmpty(Queue* queue){

  return q->front == -1;

}


int isFull(Queue* queue){

  return q->front == ((q->rear+1)%(q->capacity));

} 


int main(){

  Queue* queue =  createQueue(5);

  enqueue()

}