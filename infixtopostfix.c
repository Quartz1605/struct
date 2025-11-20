#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>

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

int precedence(char ch){

  if(ch == '*' || ch == '/') return 2;
  if(ch == '+' || ch == '-') return 1;

  else return 0;

}

int isComparator(char ch){
  
  if(ch == '*' || ch == '/' || ch == '+' || ch == '-') return 1;
  
  else return 0;

}

void infixToPostfix(char infix[],char postfix[]){

  Stack* stack = createStack(100);

  int i = 0;
  int j = 0;

  while(infix[i] != '\0'){

    char ch = infix[i];

    if(isalnum(ch)){
      postfix[j++] = ch;
    }

    else if(ch == '('){
      stack->arr[++stack->top] = ch;
    }

    else if(ch == ')'){

      while(stack->top != -1 && stack->arr[stack->top] != '('){
        postfix[j++] = pop(stack);
      }

      stack->top--;

    }

    else if(isComparator(ch)){

      while(stack->top == -1 && precedence(stack->arr[stack->top]) >= precedence(ch)){
        postfix[j++] = pop(stack);
      }

      stack->arr[++stack->top] = ch;

    }

    i++;


  }

  while(stack->top != -1){
    postfix[j++] = pop(stack);
  }

  
  postfix[j] = '\0';

  printf("%s",postfix);

}


int main(){

  char infix[] = "(a+b)*(c-d)";
  char postfix[] = "";

  infixToPostfix(infix,postfix);

}