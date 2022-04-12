#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct node {
  int valor;
  struct node *prox;
} Node; /* é criada um tipo chamado Node, que contém os campos valor
        e ponteiro para o próximo Node [valor|*prox] -> [valor|*prox] */

typedef struct {
  Node *head, *tail;
  int tam;
} Lista;

// funcao que adiciona um novo elemento ao final da lista
bool append(Lista *lista, int valor) {
  Node *novo = (Node*) malloc(sizeof(Node));
  novo-> valor = valor;

  if (lista-> head == NULL) {
    lista-> head = novo;
    lista-> tail = novo;
    novo-> prox = NULL;
  } else {
    lista-> tail-> prox = novo; 
    lista-> tail = novo; // o novo numero sera o tail da lista
    novo-> prox = NULL;
  }
  lista-> tam++;
  return true;
};

bool insert(Lista *lista, int valor, int position) {
  Node *novo = (Node*) malloc(sizeof(Node));
  Node *antecessor = NULL;
  novo-> valor = valor;
  Node *atual = lista-> head;

  for (int index = 0; index != position; index++) {
    antecessor = atual;
    atual = atual-> prox;
  }
  antecessor-> prox = NULL;
  antecessor-> prox = novo;
  novo-> prox = atual;
  lista-> tam++;
}

void printList(Lista *lista) {
  Node *current = lista-> head;
  printf("Tamanho da lista: %i\n", lista-> tam);
  
  printf("[");
  while (current != NULL) {
      printf("%d-> ", current-> valor);
      current = current-> prox;
  }
  printf("NULL]");
  printf("\n\n");
};

bool findElem(Lista *lista, int elem) {
  Node *pointer = lista-> head;
  int index;
  index = 0;

  while (pointer) {
    if (pointer-> valor == elem) {
      printf("\nElemento encontrado: %i, indice: %i\n", elem, index);
      return true;
    };
    pointer = pointer-> prox;
    index++;
  }
  printf("Elemento não encontrado\n");
  return false;
};

void isEmpty(Lista *lista) {
  if (lista-> head == NULL) {
    printf("True\n");
  } else {
    printf("False\n");
  }
}

void removeNode(Lista *lista, int elem) {
  Node *atual = (Node*) malloc(sizeof(Node));
  Node *antecessor = NULL;
  atual = lista-> head;

  while ((atual != NULL) && (atual-> valor != elem)) {
    antecessor = atual;
    atual = atual-> prox;
  }
  if ((atual != NULL) && (atual-> valor == elem)) {
    atual == NULL;
    antecessor-> prox = atual-> prox;
  }
  lista-> tam--;
  free(atual);
};

int main () {
  Lista lista;
  lista.head = NULL;
  lista.tam = 0;
  append(&lista, 7);
  append(&lista, 8);
  append(&lista, 10);
  append(&lista, 11);
  append(&lista, 12);  
  
  //isEmpty(&lista);
  findElem(&lista, 7);
  printList(&lista);
  insert(&lista, 9, 2);
  // removeNode(&lista, 9);
  printList(&lista);
  // printf("%i\n", lista.tail-> valor);
  return 0;
};
