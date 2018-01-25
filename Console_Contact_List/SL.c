#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

extern struct Node* new_node(char*, char*);
extern void delete_node(list*, int);

struct data {
	char name[21];
	char phone_nr[11];
};

void save_contacts(list *l) {
	FILE *f;

	fopen_s(&f, "contact_list.bin", "wb");

	struct Node *tmp = l->first;

	while (tmp != NULL) {
		struct data tmp_data;

		strcpy_s(tmp_data.name, 21, tmp->name);
		strcpy_s(tmp_data.phone_nr, 11, tmp->phone_nr);

		fwrite(&tmp_data, sizeof(struct data), 1, f);

		tmp = tmp->next_node;
	}

	fclose(f);
	printf("Saved succesfully!\n");
}

void load_contacts(list *l) {
	FILE *f;

	fopen_s(&f, "contact_list.bin", "rb");

	l->first = NULL;
	l->last = NULL;

	while (!feof(f)) {
		struct data tmp_data;

		fread(&tmp_data, sizeof(struct data), 1, f);
		struct Node *tmp = new_node(tmp_data.name, tmp_data.phone_nr);

		if (l->first == NULL) {
			l->first = tmp;
			l->last = tmp;
		}
		else {
			l->last->next_node = tmp;
			tmp->prev_node = l->last;
			l->last = tmp;
		}
	}

	delete_node(l, l->last->id);

	fclose(f);
	printf("Loaded succesfuly!\n");
}