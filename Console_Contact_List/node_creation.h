#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "canvas_ui.h"
#include "node_sort.h"

extern void set_display_page();
extern void draw_active_page();

struct Node* new_node(char*, char*);
struct Node* add_node_to_end(list*, struct Node*);
void add_new_contact();