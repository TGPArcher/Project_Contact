#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "allegro5\allegro.h"

//
void print_node(struct Node *n) {
	if (n != NULL) {
		printf("***\n");
		printf("ID: %d\n", n->id);
		printf("Nume: %s\n", n->name);
		printf("Phone Number: %s\n", n->phone_nr);
	}
}
//
void print_list(struct Node **n) {
	if ((*n) != NULL) {
		struct Node *tmp_node = (*n);
		print_node((*n));

		while (tmp_node->next_node != NULL) {
			tmp_node = tmp_node->next_node;
			print_node(tmp_node);
		}
	}
	else
		printf("The contact list is empty!\n");
}