#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

extern void print_node(struct Node*);

void search_by_name(list *c) {
	char search[21];
	printf("What name you want to search?\n");
	scanf_s("%20s", &search, 21);

	struct Node *tmp = c->first;
	while (tmp != NULL) {
		if (strstr(tmp->name, search) != NULL)
			print_node(tmp);

		tmp = tmp->next_node;
	}
}