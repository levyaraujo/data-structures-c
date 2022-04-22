#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_RESET   "\x1b[0m"

typedef struct node {
  int valor;
  struct node *prox;
} Node; /* é criada um tipo chamado Node, que contém os campos valor
        e ponteiro para o próximo Node [valor|*prox] -> [valor|*prox] */

// definindo a estrutura da lista
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

// o usuário escolhe onde adicionar o elemento
bool insert(Lista *lista, int valor, int position) {
  Node *novo = (Node*) malloc(sizeof(Node));
  Node *antecessor = NULL;
  novo-> valor = valor;
  Node *atual = lista-> head;

  for (int index = 0; index != position; index++) {
    antecessor = atual;
    atual = atual-> prox;
  }
  antecessor-> prox = novo;
  novo-> prox = atual;
  lista-> tam++;
  return true;
}

void printList(Lista *lista) {
  Node *current = lista-> head;
  printf("\n\nTamanho da lista: %i\n", lista-> tam);
  printf(ANSI_COLOR_BLUE);
  printf("[");
  while (current != NULL) {
      printf("%d-> ", current-> valor);
      current = current-> prox;
  }
  printf("NULL]" ANSI_COLOR_RESET);
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
  
  append(&lista, 1);
  printList(&lista);

  return 0;
};
