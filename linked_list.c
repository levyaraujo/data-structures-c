#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct node {
  int valor;
  struct node *prox;
} Node; // é criada um tipo chamado Node, que contém os campos valor
        // e ponteiro para o próximo Node [valor|*prox] -> [valor|*prox]

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

bool elemIndex(Lista *lista, int indice) {
  Node *pointer = lista-> head;
  int i;
  i = 0;

  while (pointer) {
    if (pointer-> valor == indice) {
      printf("%i\n", i);
      return true;
    } 
    pointer = pointer-> prox;
    i++;
    return false;
  }
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
  Node *antecessor = NULL;
  Node *atual = lista-> head;

  while ((atual != NULL) && (atual-> valor != elem)) {
    antecessor = atual;
    atual = atual-> prox;
  }
  if ((atual != NULL) && (atual-> valor == elem)) {
    atual == NULL;
    antecessor-> prox = atual-> prox;
  }
  lista-> tam--;
};

int main () {
  Lista lista;
  lista.head = NULL;
  lista.tam = 0;
  append(&lista, 7);
  append(&lista, 8);
  append(&lista, 9);
  append(&lista, 2);
  
  //isEmpty(&lista);
  findElem(&lista, 7);
  printList(&lista);
  removeNode(&lista, 9);
  printList(&lista);
  // printf("%i\n", lista.tail-> valor);
  return 0;
};
