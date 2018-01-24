#pragma once
#include "list.h"
#include <stdlib.h>
#include <string.h>
#include "canvas_ui.h"

struct Node* new_node(char*, char*);
struct Node* add_node_to_end(list*, struct Node*);
void print_list_to_canvas(CANVAS*, struct Node*);