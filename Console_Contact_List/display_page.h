#pragma once
#include "list.h"
#include "canvas_ui.h"
#include "c_init_elements.h"

extern void search_by_name(list *c, char *search);
extern void set_add_page();

CANVAS display_page();
void print_list_to_canvas(CANVAS*, struct Node*);