#pragma once
#include "list.h"
#include "c_init_elements.h"

extern draw_canvas(CANVAS*);
extern struct Node* new_node_d(char *, char *);
struct Node* add_node_to_end(list *, struct Node*);
extern void print_list_to_canvas(CANVAS *, struct Node *);

void draw_active_canvas();
void set_add_page();
void set_display_page();

CANVAS add_page();
CANVAS display_page();
