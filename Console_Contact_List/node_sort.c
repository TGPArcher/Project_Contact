#include "node_sort.h"

void sort_list(list *contacts) {
	int changed = 1;

	struct Node *tmp;
	while (changed) {
		changed = 0;
		tmp = contacts->first;

		while (tmp && tmp->next_node) {
			if (compare_nodes(tmp, tmp->next_node)) {
				swap_nodes(tmp, tmp->next_node);
				changed = 1;
			}
			tmp = tmp->next_node;
		}
	}

	tmp = contacts->first;
	while (tmp->prev_node)
		tmp = tmp->prev_node;
	contacts->first = tmp;

	tmp = contacts->first;
	while (tmp->next_node)
		tmp = tmp->next_node;
	contacts->last = tmp;
}

void swap_nodes(struct Node *first, struct Node *last) {
	struct Node *tmp_first_prev = first->prev_node, *tmp_last_next = last->next_node;

	if (tmp_first_prev)
		tmp_first_prev->next_node = last;
	last->prev_node = tmp_first_prev;

	if (tmp_last_next)
		tmp_last_next->prev_node = first;
	first->next_node = tmp_last_next;

	first->prev_node = last;
	last->next_node = first;
}

int compare_nodes(struct Node *first, struct Node *last) {
	int min = get_min(strlen(first->name), strlen(last->name));

	for (int i = 0; i < min; i++) {
		if (first->name[i] > last->name[i])
			return 1;

		if (first->name[i] < last->name[i])
			return 0;
	}

	if (strlen(first->name) > strlen(last->name))
		return 1;
	else
		return 0;
}

int get_min(int a, int b) {
	if (a > b)
		return b;
	else
		return a;
}