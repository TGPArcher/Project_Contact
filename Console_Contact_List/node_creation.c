#include "node_creation.h"

extern CANVAS active_page;
extern list contacts;
unsigned int id_count = 0;

struct Node* new_node(char *_name, char *_phone) {
	struct Node *n_node = (struct Node*)malloc(sizeof(struct Node));

	strcpy_s(n_node->name, 21, _name);
	strcpy_s(n_node->phone_nr, 11, _phone);
	
	n_node->next_node = NULL;
	n_node->prev_node = NULL;

	n_node->id = id_count;
	id_count++;

	return n_node;
}

struct Node* add_node_to_end(list *c, struct Node* n_node) {
	n_node->prev_node = c->last;

	if (c->last)
		c->last->next_node = n_node;
	else
		c->first = n_node;

	return n_node;
}

void add_new_contact() {
	CANVAS_ELEMENT *tmp1 = active_page.layers[0].elements;
	CANVAS_ELEMENT *tmp2 = tmp1->next;

	if (tmp1->data.input_field.text.text != "Name" &&
		tmp2->data.input_field.text.text != "Number" &&
		tmp1->data.input_field.text.text != "Invalid name" &&
		tmp2->data.input_field.text.text != "Invalid number") {

		if (strlen(tmp1->data.input_field.text.text) <= 20 &&
			strlen(tmp2->data.input_field.text.text) <= 10) {

			struct Node *node = new_node(tmp1->data.input_field.text.text, tmp2->data.input_field.text.text);

			contacts.last = add_node_to_end(&contacts, node);
			sort_list(&contacts);

			set_display_page();
		}
		else if (strlen(tmp1->data.input_field.text.text) > 20)
			tmp1->data.input_field.text.text = "Too long";
		else if (strlen(tmp2->data.input_field.text.text) > 10)
			tmp2->data.input_field.text.text = "Too long";
	}
	else {
		if (tmp1->data.input_field.text.text == "Name")
			tmp1->data.input_field.text.text = "Invalid name";
		if (tmp2->data.input_field.text.text == "Number")
			tmp2->data.input_field.text.text = "Invalid number";
	}
		draw_active_page();
}