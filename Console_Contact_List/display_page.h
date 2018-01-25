#pragma once
#include "list.h"
#include "canvas_ui.h"
#include "c_init_elements.h"

//extern
void delete_from_canvas(int);
void search_by_name(list *c, char *search);
void set_add_page();

CANVAS display_page();
void print_list_to_canvas(CANVAS*, struct Node*);
int search_for_delete_button(CANVAS *canvas);
void add_delete_button(ANCHORS);
void remove_delete_button();