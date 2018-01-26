#include "node_search.h"
extern CANVAS active_page;

void search_by_name(list *c, char *search) {
	list filtered_list = { NULL, NULL };

	struct Node *tmp = c->first;

	while (tmp != NULL) {
		if (strstr(tmp->name, search) != NULL)
			filtered_list.last = add_node_to_end(&filtered_list, new_node(tmp->name, tmp->phone_nr));

		tmp = tmp->next_node;
	}

	print_list_to_canvas(&active_page, filtered_list.first);
}