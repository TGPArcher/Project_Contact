#include "node_list_removal.h"

void node_list_removal(struct Node *first) {
	struct Node *tmp = first;

	while (tmp->next_node)
		tmp = tmp->next_node;

	while (tmp) {
		CANVAS_ELEMENT *delete_node = tmp;
		tmp = tmp->prev_node;

		free(delete_node);
	}
}

CANVAS_ELEMENT* canvas_list_removal(CANVAS_ELEMENT *first) {

	while (first && first->next) {
		CANVAS_ELEMENT *tmp = first, *remove = NULL;

		while (tmp->next) {
			remove = tmp;
			tmp = tmp->next;
		}

		remove->next = NULL; 
		free(tmp);
	}

	free(first);

	return NULL;
}