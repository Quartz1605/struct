

#include<stdio.h>
#include<stdlib.h>


#define MAX 30
#define n 3

int arr[MAX];

int sizeOfStack = MAX/n;

int top[n];


void init(){

  for(int i=0;i<n;i++){
    top[i] = i*sizeOfStack-1;
  }

}

void push(int sn,int val){

  top[sn]++;
  arr[top[sn]] = val;

}

int pop(int sn){

  int val = arr[top[sn]];
  top[sn]--;

  return val;

}

int isFull(int sn){

  return top[sn] == (sn+1)*sizeOfStack-1;

}

int isEmpty(int sn){
  return top[sn] == (sn*sizeofStack) - 1;
}