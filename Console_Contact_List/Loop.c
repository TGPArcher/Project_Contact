#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "list.h"

extern void save_contacts(list*);
extern void load_contacts(list*);

extern struct Node* new_node_p();
extern struct Node* add_node_to_end(list*);
extern struct Node* add_node_to_start(list*);

extern void delete_node(list*, int);
extern struct Node *update_last(struct Node**);
extern struct Node *update_first(struct Node**);

extern void print_node(struct Node*);
extern void print_list(struct Node**);

extern void search_by_name(list*);

void loop() {
	list contacts = { NULL, NULL };

	while (1) {

	}
}

/*void l_main() {
	list contacts = { NULL, NULL };

	do {
		char state;

		printf("\
			1-to add a new contact\n\
			2 - to print all contacts\n\
			3 - to clear the screen\n\
			4 - to delete a contact\n\
			5 - to search by name\n\
			8 - to load from file\n\
			9 - to save to file\n\
			0 - to stop the program\n");
		state = _getch();


		if (state == '1')
			contacts.last = add_node_to_end(&contacts);
		else if (state == '2')
			print_list(&contacts.first);
		else if (state == '3')
			system("cls");
		else if (state == '4')
			delete_node(&contacts);
		else if (state == '5')
			search_by_name(&contacts);
		else if (state == '8')
			load_contacts(&contacts);
		else if (state == '9')
			save_contacts(&contacts);
		else if(state == '0')
			break;

	} while (1);
}*/
