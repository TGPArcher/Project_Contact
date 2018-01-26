#include "node_removal.h"

extern CANVAS active_page;
extern list contacts;

void delete_from_canvas(int count) {
	if (count >= 0) {
		delete_node(&contacts, count);
		print_list_to_canvas(&active_page, contacts.first);
	}
}

// delete by pos
void delete_node(list *l, int count) {
	int found = 1;

	struct Node *tmp_node = l->first;
	if (tmp_node)
		for (int i = 0; i < count; i++) {
			if (!tmp_node) {
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
