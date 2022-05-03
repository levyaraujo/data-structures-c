#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

typedef struct node {
	int data;
	struct node *prev;
	struct node *next;
} Node;

typedef struct {
	Node *head, *tail;
	int size;
} List;

int append(List *lista, int value) {
	Node *new = (Node*) malloc(sizeof(struct node));
	new-> data = value;

	if (lista-> head == NULL) {
		lista-> head = new;
		lista-> tail = new;
		new-> next = NULL;
	} else {
		lista-> tail-> next = new;
		new-> prev = lista-> tail;
		lista-> tail = new;
		lista-> tail-> next = NULL;
	}
	lista-> size++;
	return 0;
}

bool insert(List *lista, int value, int position) {
		Node *current = lista-> head;
		Node *previous = current-> prev;
		Node *new = (Node*) malloc(sizeof(Node));
		new-> data = value;

		if (position > lista-> size) {
			printf("A posicao indicada e maior que o tamanho da lista.\n");
			return false;
		} 

		for (int index = 0; index != position; index++) {
			previous = current;
			current = current-> next;
		}
		previous-> next = new;
		new-> prev = previous;
		new-> next = current;
		current-> prev = new;
		printf("Item %i adicionado a lista.\n", value);
		return true;
}

bool search(List *lista, int value) {
	Node *current = lista-> head;
	int index = 0;
	printf("\nO valor %i aparece nas seguintes posicoes: ", value);
	printf("[ ");
	while (current) {
		if (current-> data == value) {
			printf("%i, ", index);			
		}
		index++;
		current = current-> next;
	}
	printf("]\n\n");
}

void displayList(List *lista) {
	Node *current = lista-> head;
	printf("Tamanho da lista: %i\n", lista-> size);
	printf("[ ");
	for (current; current != NULL; current = current-> next) {
		printf("%d-> ", current-> data);
	}
	puts("NULL ]\n");
}

int main() {
	List lista;
	lista.head = NULL;
	lista.tail = NULL;
	lista.size = 0;

	append(&lista, 1);
	append(&lista, 2);
	append(&lista, 2);
	append(&lista, 3);
	search(&lista, 2);
	insert(&lista, 7, 1);
	displayList(&lista);
}