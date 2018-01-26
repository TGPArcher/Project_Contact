#include <stdlib.h>
#include "list.h"
#include "canvas_ui.h"

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

void canvas_list_removal(CANVAS_ELEMENT *first) {

	while (first) {
		CANVAS_ELEMENT *tmp = first;

		while (tmp->next)
			tmp = tmp->next;

		free(tmp);
	}
}