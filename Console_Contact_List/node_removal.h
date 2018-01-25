#pragma once
#include "canvas_ui.h"
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

//extern
void print_list_to_canvas(CANVAS*, struct Node*);

void delete_from_canvas(int);
void delete_node(list *l, int id);