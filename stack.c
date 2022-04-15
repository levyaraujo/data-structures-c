#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct node {
  int value;
  struct node *next;
} Node;

typedef struct {
  int size;
  Node *bottom, *top;
} Stack;

bool push(Stack *stack, int value) {
  Node *new = (Node*) malloc(sizeof(Node));
  new-> value = value;
  new-> next = NULL;

  if (stack-> bottom == NULL) {
    stack-> bottom = new;
    stack-> top = new;
    new-> next = NULL;
  } else {
    stack-> top-> next = new;
    stack-> top = new;
    new-> next =  NULL;
  }
  stack-> size++;
  return true;
}

bool pop(Stack *stack) {
  if (stack == NULL) return false;
  Node *prev = NULL;
  Node *bottom = stack-> bottom; 
  while (bottom-> next != NULL) {
    prev = bottom;
    bottom = bottom-> next;
  }
  prev-> next = NULL;
  stack-> top = prev;
  bottom = NULL; 
  free(bottom);
  stack-> size--;
  return true;
}

void size(Stack *stack) {
  printf("Size of the stack: %i\n", stack-> size);
}

void display(Node *bottom) {
    if (bottom == NULL) return; // base case
    display(bottom-> next);
    printf("|%i|\n", bottom-> value);
}

void peek(Stack *stack) {
  if (stack-> bottom == NULL) {
    printf("The stack is empty\n");
    return;
  } else {
    printf("Last element on stack: %i\n", stack-> top-> value);
  }
}

int main () {
  Stack stack;
  stack.bottom = NULL;
  stack.top = NULL;
  stack.size = 0;

  push(&stack, 2);
  push(&stack, 3);
  push(&stack, 4);
  push(&stack, 5);
  display(stack.bottom);
  size(&stack);
  pop(&stack);
  printf("\n");
  display(stack.bottom);
  size(&stack);
  peek(&stack);
  return 0;
}
