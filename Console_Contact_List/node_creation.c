#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int id_count = 0;

// create a new node by typing
struct Node* new_node_p() {
	struct Node *n_node = (struct Node*)malloc(sizeof(struct Node));

	printf("Name: ");
	scanf_s("%20s", n_node->name, 21);

	printf("Phone number: ");
	scanf_s("%10s", n_node->phone_nr, 11);

	n_node->next_node = NULL;
	n_node->prev_node = NULL;

	n_node->id = id_count;
	id_count++;

	return n_node;
}

struct Node* new_node_d(char *_name, char *_phone) {
	struct Node *n_node = (struct Node*)malloc(sizeof(struct Node));

	strcpy_s(n_node->name, 21, _name);
	strcpy_s(n_node->phone_nr, 11, _phone);
	
	n_node->next_node = NULL;
	n_node->prev_node = NULL;

	n_node->id = id_count;
	id_count++;

	return n_node;
}