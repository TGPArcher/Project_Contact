#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

void search_by_name(list *c, char *search) {
	struct Node *tmp = c->first;
	while (tmp != NULL) {
		if (strstr(tmp->name, search) != NULL)
//			do something with the found node

		tmp = tmp->next_node;
	}
}