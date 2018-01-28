#pragma once
#include <string.h>
#include <stdlib.h>
#include "list.h"

void sort_list(list *contacts);
void swap_nodes(struct Node *first, struct Node *last);
int compare_nodes(struct Node *first, struct Node *last);
int get_min(int a, int b);