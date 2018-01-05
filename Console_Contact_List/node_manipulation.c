#include <stdlib.h>
#include <stdio.h>
#include "list.h"

// add new node to the end of the list
struct Node* add_node_to_end(list *c) {
	struct Node *n_node = new_node_p();

	n_node->prev_node = c->last;

	if (c->last != NULL)
		c->last->next_node = n_node;
	else
		c->first = n_node;

	return n_node;
}

// add new node to the start of the list
struct Node* add_node_to_start(list *c) {
	struct Node *n_node = new_node_p();

	n_node->next_node = c->first;

	if (c->first != NULL)
		c->first->prev_node = n_node;
	else
		c->last = n_node;

	return n_node;
}

struct Node *update_last(struct Node **n) {
	struct Node *tmp_node = (*n);

	while (tmp_node->next_node != NULL)
		tmp_node = tmp_node->next_node;

	return tmp_node;
}

struct Node *update_first(struct Node **n) {
	struct Node *tmp_node = (*n);

	while (tmp_node->prev_node != NULL)
		tmp_node = tmp_node->prev_node;

	return tmp_node;
}

// delete by id
void delete_node(list *l, int id) {
	int found = 1;

	struct Node *tmp_node = l->first;
	if (tmp_node != NULL)
		while (tmp_node->id != id) {
			if (tmp_node->next_node == NULL) {
				printf("Sorry, the id you want to delete does not exist\n");
				found = 0;
				break;
			}
			else
				tmp_node = tmp_node->next_node;
		}
	else {
		found = 0;
		printf("The list is already empty!\n");
	}

	if (found) {
		if (tmp_node->prev_node == NULL && tmp_node->next_node == NULL) {
			l->first = NULL;
			l->last = NULL;
		}
		else if (tmp_node->prev_node == NULL) {
			l->first = tmp_node->next_node;
			l->first->prev_node = NULL;
		}
		else if (tmp_node->next_node == NULL) {
			l->last = tmp_node->prev_node;
			l->last->next_node = NULL;
		}
		else {
			tmp_node->prev_node->next_node = tmp_node->next_node;
			tmp_node->next_node->prev_node = tmp_node->prev_node;
		}

		free(tmp_node);
	}
}
