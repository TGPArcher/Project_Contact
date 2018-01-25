#pragma once
#include "list.h"
#include "c_init_elements.h"

extern void load_contacts(list*);
extern draw_canvas(CANVAS*);
extern CANVAS display_page();
extern CANVAS add_page();
extern void print_list_to_canvas(CANVAS *, struct Node *);

void canvas_data_init();
void draw_active_page();
void set_add_page();
void set_display_page();
