#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>


typedef struct Stack{
  int size;
  int top;
  char *arr;
}Stack;


Stack* createStack(int size){

  Stack* stack = (Stack*)malloc(sizeof(Stack));
  stack->size = size;
  stack->top = -1;

  stack->arr = (char*)malloc(sizeof(char)*size);

  return stack;

}

void push(int val,Stack* stack){

  stack->arr[++stack->top] = val;

}

char pop(Stack* stack){

  return stack->arr[stack->top--];

}

int isEmpty(Stack* stack){
  return stack->top == -1;
}

void peek(Stack* stack){
  printf("%c ", stack->arr[stack->top]);
}

int performOp(int a,char op,int b){

  if(op  == '*') return a*b;
  if(op == '/') return a/b;
  if(op == '+') return a+b;
  if(op == '-') return a-b;

  else return -1;

}


void evaluatePrefix(char prefix[]){
  

  Stack* stack = createStack(100);

  strrev(prefix);

  int i=0;
  
  while(prefix[i] != '\0'){

    char ch = prefix[i];

    if(isalnum(ch)){
      
      int n = ch - '0';

      push(n,stack);
    
    }else{

      int n1 = pop(stack);
      int n2 = pop(stack);

      int ans = performOp(n1,ch,n2);

      push(ans,stack);

    }

    
    i++;

  }

  printf("Final result is %d",pop(stack));

}


int main(){

  char prefix[] = "+9*23";

  evaluatePrefix(prefix);


} 