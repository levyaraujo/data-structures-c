#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct node {
  int value;
  struct node *next;
} Node;

typedef struct {
  int size;
  Node *head, *tail;
} Queue;

bool enqueue(Queue *queue, int value) {
  Node *new = (Node*) malloc(sizeof(Node));
  new-> value = value;
  new-> next = NULL;
  if (queue-> head == NULL) {
    queue-> head = new;
    queue-> tail = new;
    new-> next = NULL;
    return true;
  } else {
    queue-> tail-> next = new;
    queue-> tail = new;
  }
  queue-> size++;
  return true;
}

bool dequeue(Queue *queue) {
  Node *head = queue-> head;
  if (head == NULL) {
    return false;
  } else {
    queue-> head = queue-> head-> next;
    printf("%i\n", head-> value);
    free(head);
    printf("%i\n", head-> value);
  }
}

void display(Queue *queue) {
  Node *cursor = queue-> head;
  if (queue-> head == NULL) {
    printf("The queue is empty.\n");
    return;
  } else {
    for (cursor; cursor != NULL; cursor = cursor-> next) {
      printf("%i<- ", cursor-> value);
    }
    printf("TAIL\n");
  }
}

int main() {
  Queue queue;
  queue.head = NULL;
  queue.tail = NULL;
  queue.size = 0;

  enqueue(&queue, 2);
  enqueue(&queue, 3);
  enqueue(&queue, 4);
  dequeue(&queue);
  display(&queue);
}
